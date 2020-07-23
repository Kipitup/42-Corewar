/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <samisfar.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:49:08 by ssfar             #+#    #+#             */
/*   Updated: 2020/07/24 01:41:14 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Apply the function (f) to each characters of the string (s) with their
** address and index provided to allow (f) to modify the string if necessary.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (s && f)
	{
		i = 0;
		while (s[i])
		{
			f(i, s + i);
			i++;
		}
	}
}
