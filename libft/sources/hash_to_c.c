/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_to_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:07:45 by ssfar             #+#    #+#             */
/*   Updated: 2019/11/11 21:10:39 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	hash_to_c(char *key, ssize_t tab_size, char c)
{
	size_t	i;

	i = 0;
	if (key && key[0] && tab_size > 0)
	{
		while (key[i] && key[i] != c)
			i++;
		return ((key[0] + key[i]) % tab_size);
	}
	return (-1);
}