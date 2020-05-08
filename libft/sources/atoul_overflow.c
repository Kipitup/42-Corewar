/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoul_overflow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 20:00:32 by ssfar             #+#    #+#             */
/*   Updated: 2020/05/08 20:00:32 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	atoul_overflow(const char *str, unsigned long long *result)
{
	unsigned long long	prev;
	t_bool			overflow;

	overflow = false;
	if (!str || !result)
		return (overflow);
	*result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		prev = *result;
		*result = *result * 10 + (*(str++) - '0');
		if (*result < prev)
			overflow = true;
	}
	return (overflow);
}

/*
** Convert a number written in ascci to the pointed unsigned long long in
** parameters, without taking the sign in account.
** If the pointed value is overflowed the function return 1, else 0.
** <I> Before the number is stored, the value pointed is set to 0 but only
** if the string and pointer are not NULL.
*/