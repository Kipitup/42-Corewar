/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <samisfar.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:30:47 by ssfar             #+#    #+#             */
/*   Updated: 2020/07/23 02:06:27 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Intake a float plited in two part and roughly add one to the last digit 
** of the mantissa.
** Then apply the needed modifications to the other digits.
*/

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
