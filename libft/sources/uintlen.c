/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uintlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:50:38 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 17:59:34 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return the ammount of digits which compose the unsigned number (unb).
*/

uint_fast8_t	uintlen(size_t unb)
{
	uint_fast8_t	len;

	if (unb == 0)
		return (1);
	len = 0;
	while (unb != 0)
	{
		len++;
		unb /= 10;
	}
	return (len);
}
