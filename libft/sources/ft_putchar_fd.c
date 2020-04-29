/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:12:50 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 14:36:51 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Print the character (c) in the file correponding to (fd).
*/

void	ft_putchar_fd(int_fast8_t c, int_fast16_t fd)
{
	write(fd, &c, 1);
}
