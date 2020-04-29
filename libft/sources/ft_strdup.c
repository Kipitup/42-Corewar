/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:43:48 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 12:39:31 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return a copy of the string (s1).
** <i> The output string is malloced.
*/

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dst;

	if (!s1 || !(dst = malloc(sizeof(*dst) * ft_strlen(s1) + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
