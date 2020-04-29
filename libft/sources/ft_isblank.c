/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 21:59:13 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 17:37:56 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return 1 if the character (c) is a space or a tab, otherwise return 0.
*/

uint_fast8_t	ft_isblank(int_fast8_t c)
{
	return (c != '\t' && c != ' ' ? 0 : 1);
}
