/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 11:13:19 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/14 18:03:30 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Write (n) zeroed bytes to the string (s).
** <i> Does nothing if n < 0.
*/

void	*ft_bzero(void *s, size_t n)
{
	return (ft_memset(s, '\0', n));
}
