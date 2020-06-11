/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_asm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 16:52:32 by sadahan           #+#    #+#             */
/*   Updated: 2020/06/11 18:33:30 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** reads file and checks for errors,
** parses file, creates new file .cor
** then writes header and instructs into file.cor
*/

static t_dstring	*read_file(char *str)
{
	int				fd;
	int				ret;
	char			buff[4096];
	t_dstring		*file;

	file = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (NULL);
	if (!(file = create_dstring(4096, "")))
		error_malloc(-1);
	while ((ret = read(fd, buff, 4095)))
	{
		if (ret == -1)
			return (delete_dstring(file));
		buff[ret] = '\0';
		if (buff[0] == '\0')
			return (delete_dstring(file));
		if (!(file = push_str(file, buff)))
			error_malloc(-1);
	}
	close(fd);
	if (!file->str)
		return (delete_dstring(file));
	return (file);
}

static void			write_instruct(int fd, int nb, int bytes)
{
	int				bits;
	unsigned char	res;

	bits = (bytes - 1) * 8;
	while (bits >= 0)
	{
		res = nb >> bits;
		bits -= 8;
		write(fd, &res, 1);
	}
}

static void			create_file(char *name, t_inst **instructs,
					t_header *header)
{
	int				fd;
	t_inst			*curr;
	int				n;

	curr = *instructs;
	if (!(fd = open(name, O_CREAT | O_TRUNC | O_RDWR, 0666)))
		error_malloc(-3);
	write(fd, header, sizeof(t_header));
	while (curr)
	{
		n = -1;
		if (curr->nb_args == 0)
			break ;
		write_instruct(fd, curr->opcode, 1);
		if (curr->typecode)
			write_instruct(fd, curr->typecode, 1);
		while (++n < curr->nb_args)
			write_instruct(fd, curr->args[n].val, curr->args[n].size);
		curr = curr->next;
	}
	write(1, "Writing output program to ", 26);
	write(1, name, ft_strlen(name));
	write(1, "\n", 1);
	close(fd);
}

int					parse_file(char *str, char *name)
{
	t_dstring		*file;
	t_header		*header;
	t_pos			*p;
	t_inst			*instructs;

	if (!(file = read_file(str)))
		error_malloc(-2);
	p = NULL;
	instructs = NULL;
	if (!(header = ft_memalloc(sizeof(t_header)))
		|| !(p = init_pos(p)))
		error_malloc(-1);
	if (!(fill_header(p, header, file->str)))
		return (free_return(file, header, p, 0));
	if (!(instructs = fill_instructs(p, instructs, file->str)))
		return (free_return(file, header, p, 0));
	fill_prog_size(header, &instructs);
	create_file(name, &instructs, header);
	delete_struct(&instructs);
	return (free_return(file, header, p, 1));
}
