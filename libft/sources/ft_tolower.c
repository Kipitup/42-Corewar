/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:49:08 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/14 16:53:09 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return the lowercase version of the ascii letter (c).
*/

int_fast8_t	ft_tolower(int_fast8_t c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
