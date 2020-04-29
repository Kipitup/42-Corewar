/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:03:01 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/14 17:30:53 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Append a copy of (n) characters from the string (s2) to the end of (s1).
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (s1 && s2)
	{
		i = 0;
		while (s1[i])
			i++;
		while (*s2 && n > 0)
		{
			s1[i++] = *s2++;
			n--;
		}
		s1[i] = '\0';
	}
	return (s1);
}
