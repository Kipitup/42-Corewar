/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <samisfar.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 15:08:34 by cbretagn          #+#    #+#             */
/*   Updated: 2020/07/24 12:11:41 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

/*
** Function usable by process (read 42 corewar pdf subject for more infos).
*/

void	ft_fork(t_vm *vm, t_process *cur)
{
	short	index;

	index = get_mem(vm, cur->pc, 1, 2);
	create_new_process(vm, cur);
	vm->process->pc = (cur->pc + (index % IDX_MOD)) % MEM_SIZE;
	cur->pc = (cur->pc + 3) % MEM_SIZE;
}

/*
** Function usable by process (read 42 corewar pdf subject for more infos).
*/

void	ft_lfork(t_vm *vm, t_process *cur)
{
	short	index;

	index = lget_mem(vm, cur->pc, 1, 2);
	create_new_process(vm, cur);
	vm->process->pc = (cur->pc + index) % MEM_SIZE;
	cur->pc = (cur->pc + 3) % MEM_SIZE;
}
