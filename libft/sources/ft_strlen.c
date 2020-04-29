/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:37:25 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 12:14:40 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Count the length of the string (s) up to the first '\0' encountered.
*/

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s)
		while (s[len])
			len++;
	return (len);
}
