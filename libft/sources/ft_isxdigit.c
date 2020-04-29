/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 22:55:11 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 17:40:14 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return 1 if (c) is represent an hexadecimal character, otherwise return 0.
*/

uint_fast8_t	ft_isxdigit(int_fast8_t c)
{
	return (ft_isdigit(c)
			|| (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}
