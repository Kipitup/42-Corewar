/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:15:24 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/14 17:28:08 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copy at most (len) characters from the string (src) into (dst) and return
** (dst).
*/

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	if (src && dst)
	{
		i = 0;
		while (i < len && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		while (i < len)
			dst[i++] = '\0';
	}
	return (dst);
}
