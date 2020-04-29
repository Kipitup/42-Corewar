/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:43:32 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 19:03:16 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Cocatenate (src) into (dst) and guarantee to NULL-terminate the result as
** long as there is at least one byte free in (dst).
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;
	size_t	dst_size;

	if (!src && !dst)
		return (0);
	i = 0;
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size == 0)
		return (src_size);
	if (dst_size >= size)
		src_size += size;
	else
		src_size += dst_size;
	while (dst_size < size - 1 && src[i])
		dst[dst_size++] = src[i++];
	dst[dst_size] = '\0';
	return (src_size);
}
