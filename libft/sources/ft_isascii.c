/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:18:49 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 17:37:43 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return 1 if the character (c) is an ascii character, otherwise return 0.
*/

char	ft_isascii(int c)
{
	return (c < 0 || c > 127 ? 0 : 1);
}
