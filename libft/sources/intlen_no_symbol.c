/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intlen_no_symbol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:47:45 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 19:18:51 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return the number of digit that compose (nb).
*/

uint_fast8_t	intlen_no_symbol(ssize_t nb)
{
	uint_fast8_t	len;

	if (nb == 0)
		return (1);
	len = 0;
	while (nb != 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}
