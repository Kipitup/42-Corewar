/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 16:56:38 by sadahan           #+#    #+#             */
/*   Updated: 2020/06/11 18:33:47 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** various utility functions
*/

int					endian(void)
{
	int				i;
	char			*p;

	i = 1;
	p = (char *)&i;
	if (p[0] == 1)
		return (LIL_END);
	return (BIG_END);
}

unsigned int		reverse_bytes(unsigned int n)
{
	unsigned int	rev;
	int				byte;

	rev = 0;
	byte = 0;
	while (byte <= 3)
	{
		((char*)&rev)[byte] = ((char *)&n)[3];
		byte++;
		n <<= 8;
	}
	return (rev);
}

int					is_blank(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

t_pos				*init_pos(t_pos *p)
{
	if (!(p = malloc(sizeof(t_pos))))
		error_malloc(-1);
	p->i = -1;
	p->line = 1;
	p->col = 1;
	return (p);
}

void				update_pos(t_pos *p, char c)
{
	p->col++;
	if (c == '\n')
	{
		p->line++;
		p->col = 1;
	}
}
