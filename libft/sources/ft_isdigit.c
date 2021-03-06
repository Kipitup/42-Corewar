/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:02:19 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 17:38:50 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return 1 if (c) is a digit character, otherwise return 0.
*/

uint_fast8_t	ft_isdigit(int_fast8_t c)
{
	return (c < '0' || c > '9' ? 0 : 1);
}
