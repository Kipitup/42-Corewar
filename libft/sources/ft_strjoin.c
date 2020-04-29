/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 18:39:48 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 12:24:38 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Concataned the strings (s1) and (s2) into a new NULL-terminated string.
** <i> The output string is malloced
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;

	if (s1 || s2)
		s3 = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if ((!s1 && !s2) || !s3)
		return (NULL);
	i = 0;
	if (s1)
		while (s1[i])
		{
			s3[i] = s1[i];
			i++;
		}
	if (s2)
		while (*s2)
			s3[i++] = *s2++;
	s3[i] = '\0';
	return (s3);
}
