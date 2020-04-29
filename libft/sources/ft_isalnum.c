/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:08:32 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 17:37:28 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return 1 if the character (c) represent a letter or a digit, otherwise
** return 0.
*/

uint_fast8_t	ft_isalnum(int_fast8_t c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
