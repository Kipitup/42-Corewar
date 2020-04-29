/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:53:16 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 19:04:09 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Lexicographically compare the strings (s1) and (s2).
** Return an integer greater than, equal to, or less than 0, according as the
** string (s1) is greater than, equal to, or less than the string (s2).
*/

int_fast16_t	ft_strcmp(const char *s1, const char *s2)
{
	if (s1 && s2)
	{
		while (*s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		return ((uint8_t)(*s1) - (uint8_t)(*s2));
	}
	if (s1 || s2)
		return (1);
	return (0);
}
