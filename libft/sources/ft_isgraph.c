/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgraph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 22:28:09 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 19:09:56 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return 1 if (c) is any printing character except space (` ') and other
** locale-specific space-like characters, otherwise return 0.
*/

uint_fast8_t	ft_isgraph(int_fast8_t c)
{
	return (ft_isprint(c) && c != ' ');
}
