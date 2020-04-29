/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:20:22 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/14 14:25:32 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locate and return the first occurrence of the character c in the string s.
*/

char	*ft_strchr(const char *s, int_fast8_t c)
{
	if (s)
	{
		while (*s && *s != c)
			s++;
		if (*s == c)
			return ((char*)s);
	}
	return (NULL);
}
