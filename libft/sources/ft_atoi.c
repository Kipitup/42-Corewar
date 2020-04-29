/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:06:49 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 19:10:03 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Convert a number written in ascci to an ssize_t integer.
*/

ssize_t	ft_atoi(const char *str)
{
	ssize_t			nb;
	int_fast8_t		positive;

	if (!str)
		return (0);
	nb = 0;
	positive = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		positive = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		nb = nb * 10 + (*(str++) - '0') * positive;
		if (positive == 1 && nb < 0)
			return (0);
		else if (positive != 1 && nb > 0)
			return (-1);
	}
	return (nb);
}
