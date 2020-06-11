/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_revasm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 19:10:30 by sadahan           #+#    #+#             */
/*   Updated: 2020/06/11 18:32:27 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "revasm.h"

char			*read_file(char *str, t_header *header)
{
	int			fd;
	size_t		ret;
	char		*code;
	size_t		size;

	code = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = read(fd, header, sizeof(t_header));
	if (ret < sizeof(t_header))
		return (error_read(header, code));
	if (reverse_bytes(header->magic) != COREWAR_EXEC_MAGIC)
		return (error_read(header, code));
	size = reverse_bytes(header->prog_size) + 1;
	if (!(code = ft_memalloc(sizeof(char) * size)))
		error_malloc(-1);
	ret = read(fd, code, size);
	if (ret < size - 1)
		return (error_read(header, code));
	close(fd);
	return (code);
}

static void		write_header(int fd, t_header *header)
{
	write(fd, ".name\t\"", 7);
	write(fd, header->prog_name, ft_strlen(header->prog_name));
	write(fd, "\"\n.comment\t\"", 12);
	write(fd, header->comment, ft_strlen(header->comment));
	write(fd, "\"\n\n", 3);
}

static void		write_instruct(int fd, t_revargs *args)
{
	if (args->type == T_REG)
		write(fd, "r", 1);
	if (args->type == T_DIR)
		write(fd, "%", 1);
	ft_putnbr_fd(args->val, fd);
}

void			write_file(char *name, t_revinst **instructs,
				t_header *header)
{
	int			fd;
	t_revinst	*curr;
	int			n;

	curr = *instructs;
	if (!(fd = open(name, O_CREAT | O_TRUNC | O_RDWR, 0666)))
		error_malloc(-3);
	write_header(fd, header);
	while (curr)
	{
		n = -1;
		if (curr->nb_args == 0)
			break ;
		write(fd, curr->name, ft_strlen(curr->name));
		write(fd, "\t", 1);
		while (++n < curr->nb_args)
		{
			write_instruct(fd, &curr->args[n]);
			if (n < (curr->nb_args - 1))
				write(fd, ", ", 2);
		}
		write(fd, "\n", 1);
		curr = curr->next;
	}
	close(fd);
}
