/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <samisfar.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 02:33:41 by ssfar             #+#    #+#             */
/*   Updated: 2020/07/24 12:22:03 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

/*
** Allocate a new process.
** If a (parent) process is given, the new process will take its proprieties.
*/

void	create_new_process(t_vm *vm, t_process *parent)
{
	t_process	*new_process;

	if (!(new_process = malloc(sizeof(*new_process))))
		exit_failure(vm, "Malloc Error", NULL, false);
	if (parent != NULL)
		*new_process = *parent;
	else
	{
		new_process->carry = false;
		new_process->live = false;
		new_process->wait_cylces = 0;
		bzero(new_process->reg, sizeof(*(new_process->reg)) * REG_NUMBER);
	}
	new_process->opcode = 0;
	new_process->next = vm->process;
	vm->process = new_process;
}

void	free_all(t_vm *vm)
{
	free(vm->player);
	free(vm->window);
	free_process_list(vm);
}

void	free_process_list(t_vm *vm)
{
	t_process	*tmp;
	t_process	*del;

	tmp = vm->process;
	while (tmp != NULL)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
		del = NULL;
	}
}
