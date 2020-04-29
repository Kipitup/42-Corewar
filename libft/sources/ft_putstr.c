/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:50:33 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 14:28:06 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Print the string (s) in the standard output.
*/

void	ft_putstr(char const *s)
{
	if (s)
		while (*s)
			ft_putchar(*s++);
}
