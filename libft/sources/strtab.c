/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 11:48:28 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 18:13:35 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Create and return a string table of (x) strings that can contain (y)
** characters.
** The tab and all strings are terminated by '\0'.
** <i> The output tab and the strings inside are malloced.
*/

char	**strtab(ssize_t x, ssize_t y)
{
	char	**strtab;
	ssize_t tmp;

	strtab = NULL;
	if (x != 0 || y != 0)
	{
		if (!(strtab = malloc(sizeof(*strtab) * (x + 1))))
			return (NULL);
		strtab[x] = 0;
		tmp = 0;
		while (tmp < x)
		{
			if (!(strtab[tmp] = malloc(sizeof(**strtab) * (y + 1))))
			{
				while (--tmp > 0)
					free(strtab[tmp]);
				free(strtab);
				return (NULL);
			}
			strtab[tmp++][y] = '\0';
		}
	}
	return (strtab);
}
