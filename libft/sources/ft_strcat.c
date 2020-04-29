/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:43:15 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 12:48:18 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Append a copy the string (s2) to the end of (s1).
*/

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;

	if (s1 && s2)
	{
		i = 0;
		while (s1[i])
			i++;
		while (*s2)
			s1[i++] = *s2++;
		s1[i] = '\0';
	}
	return (s1);
}
