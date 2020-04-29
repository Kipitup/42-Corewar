/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_float_mantissa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:27:46 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 19:20:48 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
