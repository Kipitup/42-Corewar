/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:53:12 by ssfar             #+#    #+#             */
/*   Updated: 2019/11/08 18:07:05 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return the convertion of an unsigned number to an ascii string.
** <i> The output string is malloced.
*/

char	*utoa(size_t unb)
{
	char			*str;
	uint_fast8_t	len;

	len = uintlen(unb);
	if (!(str = malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	if (unb == 0)
		str[0] = '0';
	while (unb != 0)
	{
		str[len--] = unb % 10 + '0';
		unb /= 10;
	}
	return (str);
}
