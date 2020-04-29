/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:15:18 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 14:29:12 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Print the string (s) in the file corresponding to (fd).
*/

void	ft_putstr_fd(char const *s, int_fast16_t fd)
{
	if (s)
		while (*s)
			ft_putchar_fd(*s++, fd);
}
