/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_asm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 16:54:39 by sadahan           #+#    #+#             */
/*   Updated: 2020/06/11 18:32:35 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Fill Header as in op.h with champion name
** and comment, instructs size and magic number
** Associated file : check_header.c
*/

void		fill_prog_size(t_header *header, t_inst **instructs)
{
	unsigned int		size;

	size = instructs_size(instructs);
	if (endian() == LIL_END)
		header->prog_size = reverse_bytes(size);
	else
		header->prog_size = size;
}

static void	fill_magic_number(t_header *header)
{
	if (endian() == LIL_END)
		header->magic = reverse_bytes(COREWAR_EXEC_MAGIC);
	else
		header->magic = COREWAR_EXEC_MAGIC;
}

int			fill_name_comment(char *file, t_pos *p, t_header *header, char *cmd)
{
	int		start;
	char	*name;

	start = ++p->i;
	while (file[p->i] && file[p->i] != '"')
		update_pos(p, file[p->i++]);
	if (!file[p->i])
	{
		error_asm("Champion name and comment must end by \"\n",
			p->line, p->col);
		return (0);
	}
	if (!(name = ft_strsub(file, start, p->i - start)))
		error_malloc(-1);
	if (ft_strlen(name) > (!(ft_strcmp(cmd, NAME_CMD_STRING)) ?
		PROG_NAME_LENGTH : COMMENT_LENGTH))
		error_asm("Champion name or comment is too long\n", p->line, p->col);
	else
	{
		ft_memcpy((!(ft_strcmp(cmd, NAME_CMD_STRING)) ?
			header->prog_name : header->comment), name, ft_strlen(name));
		return (del_str(name, 1));
	}
	return (del_str(name, 0));
}

t_pos		*fill_header(t_pos *p, t_header *header, char *file)
{
	int		check;

	check = 0;
	fill_magic_number(header);
	while (file && check < 2)
	{
		skip_blank_or_comment(file, p);
		if (file[p->i] != '.')
			return (error_asm("File must start with champion "
				"name and comment\n", p->line, p->col));
		else if (check_command(file, p, header) == 0)
			return (NULL);
		check++;
		if (!(check_endline(file, p)))
			return (error_asm("Missing newline after "
				"champion name or comment\n", p->line, p->col));
	}
	return (p);
}
