/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:42:35 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 19:58:27 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return the number of words delimited by the character (separator) inside the
** string (str).
*/

size_t	count_word(const char *s, int_fast8_t separator)
{
	size_t	word;

	word = 0;
	if (s)
		while (*s)
		{
			while (*s == separator)
				s++;
			if (*s)
				word++;
			while (*s && *s != separator)
				s++;
		}
	return (word);
}
