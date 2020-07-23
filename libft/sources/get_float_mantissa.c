/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_float_mantissa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <samisfar.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:27:46 by ssfar             #+#    #+#             */
/*   Updated: 2020/07/23 02:01:28 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Roughly convert the (precision) first numbers of the mantissa from a floating
** point number (fnb) into a malloced string.
*/

char	*get_float_mantissa(long double fnb, uint_fast8_t precision)
{
	size_t			integer;
	char			*mantissa;
	uint_fast8_t	i;

	if (precision < 1
		|| !(mantissa = malloc(sizeof(*mantissa) * precision + 1)))
		return (NULL);
	if (fnb < 0)
		fnb = -fnb;
	integer = fnb;
	fnb -= integer;
	i = 0;
	while (precision-- != 0)
	{
		fnb *= 10;
		integer = fnb;
		mantissa[i++] = '0' + integer;
		fnb -= integer;
	}
	mantissa[i] = '\0';
	return (mantissa);
}
