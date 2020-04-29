/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:26:45 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 14:33:14 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Print the signed number (n) as characters to the file corresponding to (fd).
*/

void	ft_putnbr_fd(ssize_t n, int_fast16_t fd)
{
	size_t	unb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		unb = -n;
	}
	else
		unb = n;
	if (unb >= 10)
		ft_putnbr_fd(unb / 10, fd);
	ft_putchar_fd(unb % 10 + '0', fd);
}
