/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_numeric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:13:04 by ssfar             #+#    #+#             */
/*   Updated: 2020/03/10 21:12:09 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Check if the string (str) contain an only contain numerical characters and
** signs at start, if so the function return 1 otherwise 0.
*/

uint_fast8_t	str_is_numeric(char *str)
{
	if (!str)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	if (ft_isdigit(*str++))
	{
		while (ft_isdigit(*str))
			str++;
		return (*str == '\0');
	}
	return (0);
}
