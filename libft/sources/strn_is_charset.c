/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strn_is_charset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 22:59:59 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 20:10:21 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Check if the (n) first characters of the string (str) are only characters
** from (charset).
*/

uint_fast8_t	strn_is_charset(char *str, char *charset, size_t n)
{
	if (str && charset)
	{
		while (*str && ischarset(*str, charset) && n != 0)
		{
			str++;
			n--;
		}
		if (*str == '\0' || n == 0)
			return (1);
	}
	if (str || charset)
		return (0);
	return (1);
}
