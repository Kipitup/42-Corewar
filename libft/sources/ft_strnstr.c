/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:36:27 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/14 17:25:30 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locates the first occurrence of the string (needle) in the string (haystack)
** where not more than (len) characters of (haystack) are searched.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	if (!haystack || !needle)
		return (NULL);
	i = 0;
	while (haystack[i] && *needle && i != len)
	{
		tmp = i;
		j = 0;
		while (haystack[tmp] == needle[j]
				&& haystack[tmp++] && needle[j++] && tmp != len)
			;
		if (!needle[j])
			return ((char*)haystack + i);
		i++;
	}
	return (!*needle ? (char*)haystack : NULL);
}
