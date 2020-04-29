/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:26:42 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 19:06:47 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Lexicographically compare the (n) first characters of the strings (s1) and
** (s2).
** Return an integer greater than, equal to, or less than 0, according as the
** string (s1) is greater than, equal to, or less than (s2).
*/

int_fast16_t	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	if (s1 && s2)
	{
		while (*s1 && *s2 && *s1 == *s2 && n > 1)
		{
			s1++;
			s2++;
			n--;
		}
		return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	if (s1)
		return ((unsigned char)*s1);
	else if (s2)
		return (-((unsigned char)*s2));
	return (0);
}
