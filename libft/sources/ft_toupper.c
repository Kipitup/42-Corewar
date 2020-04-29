/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:41:11 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/14 16:52:41 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return the uppercase version of the ascii letter (c).
*/

int_fast8_t	ft_toupper(int_fast8_t c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
