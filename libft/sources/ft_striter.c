/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:42:34 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 12:37:57 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Apply the function (f) to each characters of the string (s) whit their
** address provided to allow (f) to modify the string if necessary.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (f && s)
		while (*s)
			f(s++);
}
