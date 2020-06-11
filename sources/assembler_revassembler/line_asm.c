/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 16:55:06 by sadahan           #+#    #+#             */
/*   Updated: 2020/06/11 18:33:11 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** various utility functions
*/

int			skip_blank_or_comment(char *file, t_pos *p)
{
	int		endline;

	endline = 0;
	while (file[++p->i] && (is_blank(file[p->i])
		|| file[p->i] == COMMENT_CHAR
		|| file[p->i] == ALT_COMMENT_CHAR))
	{
		update_pos(p, file[p->i]);
		if (file[p->i] == COMMENT_CHAR
			|| file[p->i] == ALT_COMMENT_CHAR)
		{
			while (file[++p->i] && file[p->i] != '\n')
				update_pos(p, file[p->i]);
			update_pos(p, file[p->i]);
		}
		if (file[p->i] == '\n')
			endline++;
	}
	return (endline);
}

int			check_endline(char *file, t_pos *p)
{
	while (file[p->i] && file[p->i] != '\n')
	{
		update_pos(p, file[++p->i]);
		if (file[p->i] == COMMENT_CHAR
			|| file[p->i] == ALT_COMMENT_CHAR)
		{
			while (file[p->i++] && file[p->i] != '\n')
				update_pos(p, file[p->i]);
			update_pos(p, file[p->i]);
		}
		if (!file[p->i])
			return (0);
		if (!is_blank(file[p->i]))
			return (0);
	}
	return (1);
}
