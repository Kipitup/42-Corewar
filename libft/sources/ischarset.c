/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ischarset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:13:58 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 19:16:59 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return 1 if the character (c) is one of the characters from (charset)
** otherwise return 0.
*/

uint_fast8_t	ischarset(int_fast8_t c, char *charset)
{
	uint_fast8_t	same;

	same = 0;
	if (charset)
		while (*charset)
			if (c == *charset++)
				same = 1;
	return (same);
}
