/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_va_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 18:20:45 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 19:19:21 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Store and return the next variadic argument inside an unsigned integer of
** (bits) bits.
*/

size_t	get_va_uint(va_list arg, uint_fast8_t bits, uint_fast8_t z)
{
	if (z)
		return ((size_t)va_arg(arg, size_t));
	else if (bits == 32)
		return ((uint32_t)va_arg(arg, size_t));
	else if (bits == 64)
		return ((uint64_t)va_arg(arg, size_t));
	else if (bits == 8)
		return ((uint8_t)va_arg(arg, size_t));
	else
		return ((uint16_t)va_arg(arg, size_t));
}
