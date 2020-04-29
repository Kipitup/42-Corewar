/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:20:27 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 17:47:53 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Add the element (new) in head of the list
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (new && alst)
	{
		new->next = *alst;
		*alst = new;
	}
}
