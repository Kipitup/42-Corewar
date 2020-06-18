/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol_overflow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 12:55:10 by ssfar             #+#    #+#             */
/*   Updated: 2020/06/18 02:26:22 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	atol_overflow(const char *str, long long *result)
{
	long long	prev;
	signed char	mult;
	t_bool		overflow;

	overflow = false;
	if (!str || !result)
		return (overflow);
	mult = 1;
	*result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			mult = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		prev = *result;
		*result = *result * 10 + (*(str++) - '0') * mult;
		if ((*result < prev && mult == 1) || ((*result > prev && mult == -1)))
			overflow = true;
	}
	return (overflow);
}

/*
** Convert a number written in ascci to the pointed long long in parameters.
** If the pointed value is overflowed the function return 1, else 0.
** <I> Before the number is stored, the value pointed is set to 0 but only
** if the string and pointer are not NULL.
*/
