/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 02:33:41 by ssfar             #+#    #+#             */
/*   Updated: 2020/06/18 17:05:41 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	create_new_cursor(t_vm *vm, t_cursor *parent)
{
	t_cursor	*new_cursor;

	if (!(new_cursor = malloc(sizeof(*new_cursor))))
		exit_failure(vm, "Malloc Error", NULL, false);
	if (parent != NULL)
		*new_cursor = *parent;
	else
	{
		new_cursor->carry = false;
		new_cursor->live = false;
		new_cursor->wait_cylces = 0;
		bzero(new_cursor->reg, sizeof(*(new_cursor->reg)) * REG_NUMBER);
	}
	new_cursor->opcode = 0;
	new_cursor->next = vm->cursor;
	vm->cursor = new_cursor;
}

void	free_all(t_vm *vm)
{
	free(vm->player);
	free(vm->window);
	free_cursor_list(vm);
}

void	free_cursor_list(t_vm *vm)
{
	t_cursor	*tmp;
	t_cursor	*del;

	tmp = vm->cursor;
	while (tmp != NULL)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
		del = NULL;
	}
}
