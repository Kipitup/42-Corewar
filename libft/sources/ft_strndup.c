/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:59:15 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/14 17:26:59 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return a copy of (n) characters from the string (s1).
** <i> The output string is malloced.
*/

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dst;
	size_t	i;

	if (!s1 || !(dst = (char*)malloc(sizeof(*dst) * (n + 1))))
		return (NULL);
	i = 0;
	while (s1[i] && n != 0)
	{
		dst[i] = s1[i];
		i++;
		n--;
	}
	dst[i] = '\0';
	return (dst);
}
