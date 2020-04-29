/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 11:09:54 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 19:07:34 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies (n) bytes from memory area (src) to memory area (dst).
** If (dst) and (src) overlap, behavior is undefined.
** <i> Applications in which (dst) and (src) might overlap should use memmove(3)
** instead.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (dst && src)
		while (n)
		{
			n--;
			((uint8_t*)dst)[n] = ((uint8_t*)src)[n];
		}
	return (dst);
}
