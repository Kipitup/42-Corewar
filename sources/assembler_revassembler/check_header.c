/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 16:53:07 by sadahan           #+#    #+#             */
/*   Updated: 2020/06/11 18:32:02 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Checks if champion name and comment are well formated
** to fill header in file "header_asm.c"
*/

int			check_name_comment(char *file, t_pos *p, t_header *header,
				char *cmd)
{
	int		ret;

	ret = 0;
	while (file[p->i] && (file[p->i] == ' ' || file[p->i] == '\t'))
	{
		p->i++;
		p->col++;
	}
	if (file[p->i] && file[p->i] == '\n')
		error_asm("Endline after command or empty command\n", p->line, p->col);
	else if (file[p->i] && file[p->i] != '"')
		error_asm("Champion name and comment must start by \"\n",
			p->line, p->col);
	else
		ret = fill_name_comment(file, p, header, cmd);
	return (ret);
}

int			check_command(char *file, t_pos *p, t_header *header)
{
	int		start;
	char	*cmd;
	int		ret;

	ret = 0;
	start = p->i;
	while (file[p->i] && !is_blank(file[p->i]) && file[p->i] != '"')
	{
		p->col++;
		p->i++;
	}
	if (!(cmd = ft_strsub(file, start, p->i - start)))
		error_malloc(-1);
	if (!(ft_strcmp(cmd, NAME_CMD_STRING))
		|| !(ft_strcmp(cmd, COMMENT_CMD_STRING)))
		ret = check_name_comment(file, p, header, cmd);
	else
		error_asm("Command string unknown\n", p->line, p->col);
	ft_strdel(&cmd);
	return (ret);
}
