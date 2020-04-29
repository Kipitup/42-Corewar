/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upower.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:21:30 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 17:57:02 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Raise the unsigned number (unb) to the unsigned power (pow) and return the
** result.
*/

size_t	upower(size_t unb, uint_fast8_t pow)
{
	size_t	result;

	if (pow == 0)
		return (1);
	result = unb;
	while (pow-- != 1)
		result *= unb;
	return (result);
}
