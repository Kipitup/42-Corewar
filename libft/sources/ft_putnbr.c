/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:03:29 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 14:32:49 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Print the signed number (n) as characters to the standard output.
*/

void	ft_putnbr(ssize_t n)
{
	size_t	unb;

	if (n < 0)
	{
		unb = -n;
		ft_putchar('-');
	}
	else
		unb = n;
	if (unb >= 10)
		ft_putnbr(unb / 10);
	ft_putchar(unb % 10 + '0');
}
