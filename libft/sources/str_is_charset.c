/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_charset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:13:58 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 20:15:49 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Check if the characters of the string (str) are only characters from
** (charset).
*/

uint_fast8_t	str_is_charset(char *str, char *charset)
{
	if (str && charset)
	{
		while (*str && ischarset(*str, charset))
			str++;
		if (*str == '\0')
			return (1);
	}
	if (str || charset)
		return (0);
	return (1);
}
