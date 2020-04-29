/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcapitalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:47:08 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 18:33:21 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Set to uppercase the first letter of each words from the string (str) and
** lower the rest.
*/

void	strcapitalize(char *str)
{
	size_t	i;

	if (str)
	{
		i = 0;
		while (str[i])
		{
			if (ft_islower(str[i]) && (i == 0
					|| (i != 0 && !ft_isalnum(str[i - 1]))))
				str[i] -= 32;
			else if (i != 0 && ft_isupper(str[i]) && ft_isalnum(str[i - 1]))
				str[i] += 32;
			i++;
		}
	}
}
