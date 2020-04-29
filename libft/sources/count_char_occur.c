/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_char_occur.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 17:49:02 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 19:45:40 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return the number of occurrences of the character (c) inside the string
** (str).
*/

size_t	count_char_occur(char *str, int_fast8_t c)
{
	size_t	occur;

	occur = 0;
	if (str)
		while (*str)
			if (*str++ == c)
				occur++;
	return (occur);
}
