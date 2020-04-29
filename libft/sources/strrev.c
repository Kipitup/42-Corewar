/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:47:37 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 20:10:33 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Reverse the string (str).
*/

void	strrev(char *str)
{
	int_fast8_t	cache;
	int			end;
	int			i;

	if (str)
	{
		end = ft_strlen(str) - 1;
		i = 0;
		while (i < end)
		{
			cache = str[i];
			str[i++] = str[end];
			str[end--] = cache;
		}
	}
}
