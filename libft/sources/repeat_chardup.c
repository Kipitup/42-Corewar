/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_chardup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:58:19 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 19:11:00 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Create a new NULL-terminated string which is the repetition of the character
** (c) (reapeat) times.
** <i> The output string is malloced
*/

char	*repeat_chardup(char c, size_t repeat)
{
	char	*str;
	size_t	i;

	if (repeat < 1 || !(str = malloc(sizeof(*str) * (repeat + 1))))
		return (NULL);
	i = 0;
	while (repeat-- > 0)
		str[i++] = c;
	str[i] = '\0';
	return (str);
}
