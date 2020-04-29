/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:30:47 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 19:41:22 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	round_float(size_t *integer, char *mantissa)
{
	int_fast8_t i;

	i = ft_strlen(mantissa) - 1;
	while (i >= 0 && mantissa[i] == '9')
		mantissa[i--] = '0';
	if (i >= 0)
		(mantissa[i])++;
	else
		(*integer)++;
}
