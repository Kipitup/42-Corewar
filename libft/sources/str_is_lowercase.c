/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_lowercase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:28:37 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 19:07:37 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Check if the string (str) only contain lowercase letters,
** if so the function return 1 otherwise 0.
*/

uint_fast8_t	str_is_lowercase(char *str)
{
	uint_fast8_t	lower_case;

	if (!str)
		return (0);
	lower_case = ft_islower(*str++);
	while (ft_islower(*str))
		str++;
	return (*str == '\0' && lower_case);
}
