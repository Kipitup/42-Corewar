/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:56:12 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 13:12:18 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Lexicographically compare the strings (s1) and (s2) ignoring the case.
** Return an integer greater than, equal to, or less than 0, according as the
** string (s1) is greater than, equal to, or less than the string (s2).
*/

int_fast16_t	ft_strcasecmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s2 && !ft_casecmp(*s1, *s2))
	{
		s1++;
		s2++;
	}
	return (ft_casecmp(*s1, *s2));
}
