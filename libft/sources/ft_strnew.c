/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:16:28 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/14 17:26:09 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return a new string of size (len) formated to '\0'.
** <i> The output string is malloced.
*/

char	*ft_strnew(size_t size)
{
	char	*ptr;

	if (!(ptr = (char*)malloc(sizeof(*ptr) * size + 1)))
		return (NULL);
	return (ft_memset(ptr, '\0', size + 1));
}
