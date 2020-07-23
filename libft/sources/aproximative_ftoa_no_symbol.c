/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aproximative_ftoa_no_symbol.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <samisfar.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:31:55 by ssfar             #+#    #+#             */
/*   Updated: 2020/07/23 02:56:26 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Aproximatively convert a floating point number (fnb) into a NULL terminated
** string.
** Set (sharp) boolean to 1 to make sure the result always contain a '.',
** even if no digits follow it.
*/

char	*aproximative_ftoa_no_symbol(long double fnb, uint_fast8_t precision,
	t_bool sharp)
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
