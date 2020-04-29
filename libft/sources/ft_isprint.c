/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:30:02 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 17:39:14 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return 1 if (c) is any printing character including space, otherwise return
** 0.
*/

uint_fast8_t	ft_isprint(int_fast8_t c)
{
	return (c < 32 || c > 126 ? 0 : 1);
}
