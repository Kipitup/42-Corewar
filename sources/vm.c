/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 13:46:51 by ssfar             #+#    #+#             */
/*   Updated: 2020/04/29 13:46:51 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	game_loop(t_vm *vm)
{
	while (vm->cursor != NULL)
	{
		if (vm->dump && vm->cycle_counter == vm->cycle_to_dump)
			dump(vm);
		if (vm->cycle_counter == vm->cycle_to_die)
			check(vm, vm->cursor, NULL);
		uptdate_cursor(vm, vm->cursor);
		vm->cycle_counter++;
	}
}

void	check(t_vm *vm, t_cursor *cur, t_cursor *prev)
{
	while (cur != NULL)
	{
		if (cur->live == true)
		{
			cur->live = false;
			prev = cur;
			cur = cur->next;
		}
		else
			remove_cursor(vm, &cur, &prev);
	}
	if (vm->live_counter >= NBR_LIVE || vm->check_counter == MAX_CHECKS)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		if (vm->cycle_to_die > vm->cycle_counter)
			vm->cycle_to_die = 0;
		vm->live_counter = 0;
		vm->check_counter = 0;
	}
	else
		vm->check_counter++;
	vm->cycle_to_dump -= vm->cycle_counter;
	vm->cycle_counter = 0;
}

void	remove_cursor(t_vm *vm, t_cursor **cur, t_cursor **prev)
{
	if (*prev != NULL)
	{
		(*prev)->next = (*cur)->next;
		free(*cur);
		*cur = (*prev)->next;
	}
	else
	{
		vm->cursor = (*cur)->next;
		free(*cur);
		*cur = vm->cursor;
	}
}

void	uptdate_cursor(t_vm *vm, t_cursor *tmp)
{
	while (tmp != NULL)
	{
		if (tmp->jump != 0)
		{
			tmp->pc = (tmp->pc + tmp->jump) % MEM_SIZE;
			tmp->jump = 0;
		}
		else if (tmp->wait_cylces > 0)
			tmp->wait_cylces--;
		else if (tmp->opcode == 0)
		{
			tmp->opcode = vm->arena[tmp->pc];
			if (tmp->opcode > 16)
			{
				tmp->wait_cylces = 0;
				tmp->jump = 1;
			}
			// else
			//	tmp->wait_cylces = 
		}
		// else
		// function that handle opcode
		tmp = tmp->next;
	}
}
