/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strtab_offset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:26:02 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 19:21:30 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Free the strings of a string table and return NULL.
** Each strings are freed from first char + (offset) bytes.
** <i> Offset can be negative.
*/

char	**free_strtab_offset(char **tab, ssize_t offset)
{
	size_t	i;

	if (tab)
	{
		i = 0;
		while (tab[i])
		{
			free(&tab[i][offset]);
			i++;
		}
		free(tab);
	}
	return (NULL);
}
