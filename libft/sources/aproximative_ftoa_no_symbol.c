/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aproximative_ftoa_no_symbol.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:31:55 by ssfar             #+#    #+#             */
/*   Updated: 2019/11/10 16:40:33 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*aproximative_ftoa_no_symbol(long double fnb, uint_fast8_t precision,
	uint_fast8_t sharp)
{
	size_t			integer;
	char			*mantissa;
	char			*str;

	if (fnb < 0)
		fnb = -fnb;
	integer = fnb;
	mantissa = get_float_mantissa(fnb, precision);
	fnb *= upower(10, precision + 1);
	if (!mantissa && (int)fnb % 10 >= 5)
		integer++;
	else if (mantissa && (int)fnb % 10 >= 5)
		round_float(&integer, mantissa);
	if (!mantissa && !sharp)
		return (itoa_no_symbol(integer));
	str = strjoin_free(itoa_no_symbol(integer), ".", 1);
	if (mantissa)
		return (strjoin_free(str, mantissa, 3));
	return (str);
}
