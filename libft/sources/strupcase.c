/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strupcase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:33:02 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 18:11:39 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Change all the ascii letters of the string (str) to their uppercase versions.
*/

void	strupcase(char *str)
{
	size_t	i;

	if (str)
	{
		i = 0;
		while (str[i])
		{
			if (ft_islower(str[i]))
				str[i] -= 32;
			i++;
		}
	}
}
