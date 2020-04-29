/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:45:04 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 17:44:20 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return 1 if the character (c) represent a letter, otherwise return 0.
*/

uint_fast8_t	ft_isalpha(int_fast8_t c)
{
	return (ft_islower(c) || ft_isupper(c));
}
