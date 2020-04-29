/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 23:20:31 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 18:30:29 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return as a number the position of the first occurence of the character (c)
** inside the string(s).
** If (c) is not found, the position of the first '\0' is returned.
*/

size_t	strchr_len(const char *s, int_fast8_t c)
{
	size_t	len;

	len = 0;
	if (s)
		while (s[len] != c && s[len])
			len++;
	return (len);
}
