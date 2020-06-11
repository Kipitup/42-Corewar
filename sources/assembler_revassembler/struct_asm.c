/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_asm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 16:56:20 by sadahan           #+#    #+#             */
/*   Updated: 2020/06/11 18:46:25 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "revasm.h"

t_inst			*delete_elem(t_inst *elem)
{
	int			i;

	i = 0;
	ft_free_tab(elem->label);
	while (i < elem->nb_args)
	{
		ft_strdel(&(elem->args[i].label));
		i++;
	}
	free(elem);
	elem = NULL;
	return (NULL);
}

t_inst			*delete_struct(t_inst **list)
{
	t_inst		*curr;
	int			i;
	t_inst		*next;

	curr = *list;
	if (!curr)
		return (NULL);
	while (curr)
	{
		next = curr->next;
		i = 0;
		if (curr->label)
			ft_free_tab(curr->label);
		while (i < curr->nb_args)
		{
			ft_strdel(&(curr->args[i].label));
			i++;
		}
		free(curr);
		curr = next;
	}
	list = NULL;
	return (NULL);
}

void			add_to_list(t_inst **list, t_inst *new)
{
	t_inst		*curr;

	curr = *list;
	if (!curr)
	{
		*list = new;
		return ;
	}
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

void			add_to_rlist(t_revinst **list, t_revinst *new)
{
	t_revinst	*curr;

	curr = *list;
	if (!curr)
	{
		*list = new;
		return ;
	}
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

t_revinst		*delete_r_struct(t_revinst **list)
{
	t_revinst	*curr;
	t_revinst	*next;

	curr = *list;
	if (!curr)
		return (NULL);
	while (curr)
	{
		next = curr->next;
		ft_strdel(&curr->name);
		free(curr);
		curr = next;
	}
	list = NULL;
	return (NULL);
}
