/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_endian.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <samisfar.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 12:06:12 by ssfar             #+#    #+#             */
/*   Updated: 2020/07/23 02:11:56 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return the current endiannes in use.
** 0 = little endian, 1 = big endian.
*/

t_bool	big_endian(void)
{
	short			nb;
	unsigned char	*p;

	nb = 1;
	p = (unsigned char *)(&nb);
	return (p[0] == 0 ? true : false);
}
