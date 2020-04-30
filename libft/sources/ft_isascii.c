/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:18:49 by ssfar             #+#    #+#             */
/*   Updated: 2020/04/30 14:25:28 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return 1 if the character (c) is an ascii character, otherwise return 0.
*/

t_bool	ft_isascii(int c)
{
	return (c < 0 || c > 127 ? false : true);
}
