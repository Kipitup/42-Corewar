/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <samisfar.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:31:35 by cbretagn          #+#    #+#             */
/*   Updated: 2020/07/24 12:28:05 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Free a string tab and all its strings.
** Set everything to NULL.
*/

void	ft_free_tab(char **tab)
{
	int i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		i++;
	while (i >= 0)
	{
		free(tab[i]);
		tab[i] = NULL;
		i--;
	}
	free(tab);
	tab = NULL;
}
