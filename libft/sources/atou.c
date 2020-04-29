/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atou.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 10:23:30 by ssfar             #+#    #+#             */
/*   Updated: 2020/03/10 21:02:40 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Convert a number written in ascci to an size_t integer, sign is ignored.
** <I> If overflowed, output value have no sense.
*/

size_t	atou(const char *str)
{
	size_t			nb;

	if (!str)
		return (0);
	nb = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		nb = nb * 10 + (*(str++) - '0');
	return (nb);
}
