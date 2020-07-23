/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <samisfar.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 18:10:46 by ssfar             #+#    #+#             */
/*   Updated: 2020/07/24 01:41:31 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compare the (n) first characters from the string (s1) with (s2),
** return 1 if they are the same or 0 if not.
*/

uint_fast8_t	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 && !s2)
		return (1);
	else if (!s1 || !s2)
		return (0);
	while (*s1 && *s2 && n)
	{
		if (*s1 != *s2)
			return (1);
		s1++;
		s2++;
		n--;
	}
	return ((*s1 || *s2) && n ? 1 : 0);
}
