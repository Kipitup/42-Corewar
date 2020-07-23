/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <samisfar.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:08:31 by ssfar             #+#    #+#             */
/*   Updated: 2020/07/24 01:40:42 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return a memory area of the length of (size) initialised with '\0'.
** <i> The output pointer is malloced.
*/

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(size)))
		return (NULL);
	return (ft_memset(ptr, 0, size));
}
