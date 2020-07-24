/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <samisfar.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 13:46:51 by ssfar             #+#    #+#             */
/*   Updated: 2020/07/24 12:08:22 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	game_loop(t_vm *vm)
{
	int	ch;

	if (vm->visualiser == true)
		ch = getch();
	while (1)
	{
		if (vm->visualiser == true)
		{
			ch = get_visu_input(vm, ch);
			display_round(vm);
		}
		if (vm->dump && vm->cycle_counter == vm->cycle_to_dump)
		{
			if (vm->visualiser == true)
				endwin();
			dump(vm);
		}
		if (vm->cycle_counter == vm->cycle_to_die)
			check(vm, vm->process, NULL);
		if (vm->process == NULL || vm->cycle_to_die == 0)
			break ;
		update_process(vm, vm->process);
		vm->cycle_counter++;
	}
}

void	check(t_vm *vm, t_process *cur, t_process *prev)
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
			remove_process(vm, &cur, &prev);
	}
	vm->check_counter++;
	if (vm->live_counter == NBR_LIVE || vm->nbr_live_reached == true
		|| vm->check_counter == MAX_CHECKS)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->check_counter = 0;
		if (vm->cycle_to_die >= vm->cycle_counter)
			vm->cycle_to_die = 0;
	}
	vm->cycle_to_dump -= vm->cycle_counter;
	vm->cycle_counter = 0;
	vm->live_counter = 0;
	vm->nbr_live_reached = false;
}

void	remove_process(t_vm *vm, t_process **cur, t_process **prev)
{
	if (*prev != NULL)
	{
		(*prev)->next = (*cur)->next;
		free(*cur);
		*cur = (*prev)->next;
	}
	else
	{
		vm->process = (*cur)->next;
		free(*cur);
		*cur = vm->process;
	}
}

void	update_process(t_vm *vm, t_process *tmp)
{
	while (tmp != NULL)
	{
		if (tmp->opcode == 0)
		{
			tmp->opcode = vm->arena[tmp->pc];
			if (tmp->opcode == 0 || tmp->opcode > 16)
				tmp->opcode = 0;
			tmp->wait_cylces = vm->cost[tmp->opcode];
		}
		tmp->wait_cylces--;
		if (tmp->wait_cylces == 0)
		{
			if (tmp->opcode == 0)
				tmp->pc = (tmp->pc + 1) % MEM_SIZE;
			else
			{
				vm->tab[tmp->opcode](vm, tmp);
				tmp->opcode = 0;
			}
		}
		tmp = tmp->next;
	}
}
