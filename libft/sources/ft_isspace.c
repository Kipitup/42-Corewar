/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 22:01:26 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 17:39:19 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return 1 if (c) is any white-space character, otherwise return 0.
*/

uint_fast8_t	ft_isspace(int_fast8_t c)
{
	return (c < 9 || (c > 13 && c != 32) ? 0 : 1);
}
