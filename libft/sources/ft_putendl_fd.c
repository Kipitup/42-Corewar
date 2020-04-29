/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:21:05 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 14:35:57 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Print the string (s) followed by a carriage return in the file correponding
** to (fd).
*/

void	ft_putendl_fd(char const *s, int_fast16_t fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
