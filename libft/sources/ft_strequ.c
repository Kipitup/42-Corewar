/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <samisfar.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:03:16 by ssfar             #+#    #+#             */
/*   Updated: 2020/07/24 01:41:04 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compare the string (s1) with (s2),
** return 1 if they are the same or 0 if not.
*/

uint_fast8_t	ft_strequ(char const *s1, char const *s2)
{
	return (ft_strcmp(s1, s2) ? 0 : 1);
}
