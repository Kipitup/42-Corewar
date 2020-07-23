/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <samisfar.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:42:34 by ssfar             #+#    #+#             */
/*   Updated: 2020/07/24 01:41:10 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Apply the function (f) to each characters of the string (s) with their
** address provided to allow (f) to modify the string if necessary.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (f && s)
		while (*s)
			f(s++);
}
