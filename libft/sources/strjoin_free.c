/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:30:41 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 18:27:14 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Concataned the strings (s1) and (s2) into a new NULL-terminated string and
** free them or not according to the value of (to_free).
** 1 = (s1) freed, 2 = (s2), 3 = (s1) and (s2), 0 = no free.
** <i> The output string is malloced
*/

char	*strjoin_free(char *s1, char *s2, uint_fast8_t to_free)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if ((!s1 && !s2)
		|| !(s3 = malloc(sizeof(*s3) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[j])
			s3[i++] = s1[j++];
	j = 0;
	if (s2)
		while (s2[j])
			s3[i++] = s2[j++];
	s3[i] = '\0';
	if (s1 && (to_free == 1 || to_free == 3))
		free(s1);
	if (s2 && (to_free == 2 || to_free == 3))
		free(s2);
	return (s3);
}
