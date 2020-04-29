/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_no_symbol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:56:28 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 19:12:45 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Convert the signed number (nb) into a NULL-terminated string whitout sign.
*/

char	*itoa_no_symbol(ssize_t nb)
{
	char			*str;
	uint_fast8_t	len;

	len = intlen_no_symbol(nb);
	if (!(str = malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	if (nb == 0)
		str[0] = '0';
	else if (nb > 0)
		while (nb != 0)
		{
			str[len--] = nb % 10 + '0';
			nb /= 10;
		}
	else
		while (nb != 0)
		{
			str[len--] = -(nb % 10) + '0';
			nb /= 10;
		}
	return (str);
}
