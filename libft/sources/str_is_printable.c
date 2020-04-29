/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_printable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:33:15 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 19:07:09 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Check if the string (str) only contain non whitespace characters,
** if so the function return 1 otherwise 0.
*/

uint_fast8_t	str_is_printable(char *str)
{
	uint_fast8_t	printable;

	if (!str)
		return (0);
	printable = ft_isprint(*str++);
	while (ft_isprint(*str))
		str++;
	return (*str == '\0' && printable);
}
