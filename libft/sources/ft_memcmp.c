/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:41:38 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 19:09:40 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compares byte string (s1) against byte string (s2).
** Both strings are assumed to be (n) bytes long.
** Returns zero if the two strings are identical otherwise returns the diff.
*/

int_fast16_t	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (s1 && s2)
	{
		i = 0;
		while (i < n)
		{
			if (((uint8_t*)s1)[i] != ((uint8_t*)s2)[i])
				return (((uint8_t*)s1)[i] - ((uint8_t*)s2)[i]);
			i++;
		}
	}
	return (0);
}
