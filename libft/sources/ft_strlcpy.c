/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:10:35 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 12:21:25 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copy (src) into (dst) and guarantee to NULL-terminate the result as long as
** (size) if larger than 0.
*/

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	if (size && src && dst)
	{
		i = 0;
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	if (src)
		return (ft_strlen(src));
	return (0);
}
