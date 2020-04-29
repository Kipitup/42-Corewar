/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 20:05:00 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 17:39:29 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return 1 if (c) is an uppercase letter, otherwise return 0.
*/

uint_fast8_t	ft_isupper(int_fast8_t c)
{
	return (c < 'A' || c > 'Z' ? 0 : 1);
}
