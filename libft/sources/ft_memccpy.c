/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 11:23:32 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 19:08:49 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies bytes from string (src) to (dst).
** If the character (c) occurs in the string (src), the copy stops and a
** pointer to the byte after the copy of (c) in the string (dst) is returned.
** Otherwise, (n) bytes are copied, and a NULL pointer is returned.
** The source and destination strings should not overlap, as the behavior is
** undefined.
*/

void	*ft_memccpy(void *dst, const void *src, int_fast8_t c, size_t n)
{
	size_t	i;

	if (dst && src)
	{
		i = 0;
		while (i < n)
		{
			((uint8_t*)dst)[i] = ((uint8_t*)src)[i];
			if (((uint8_t*)src)[i++] == (uint8_t)c)
				return (dst + i);
		}
	}
	return (NULL);
}
