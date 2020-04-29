/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp_charset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <vrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 12:03:49 by ssfar             #+#    #+#             */
/*   Updated: 2020/03/11 13:48:08 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Lexicographically compare the characters of the strings (s1) and
** (s2) until the first difference, occurency of (c) or the end of a string.
** Return an integer greater than, equal to, or less than 0, according as the
** string (s1) is greater than, equal to, or less than (s2).
*/

uint_fast16_t	strcmp_charset(const char *s1, const char *s2, char *charset)
{
	size_t	i;

	if (s1 && s2)
	{
		while (*s1 && *s2 && *s1 == *s2)
		{
			if (charset)
			{
				i = 0;
				while (charset[i])
				{
					if (*s1 == charset[i])
						return (0);
					i++;
				}
			}
			s1++;
			s2++;
		}
		return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	if (s1)
		return ((unsigned char)*s1);
	return (s2 ? -((unsigned char)*s2) : 0);
}
