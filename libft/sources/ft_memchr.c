/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:31:29 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 14:50:32 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return the first occurrence of (c) in the string s.
*/

void	*ft_memchr(const void *s, int_fast8_t c, size_t n)
{
	size_t	i;

	if (s)
	{
		i = 0;
		while (i < n)
			if (((uint8_t*)s)[i++] == (uint8_t)c)
				return (((uint8_t*)s) + i - 1);
	}
	return (NULL);
}
