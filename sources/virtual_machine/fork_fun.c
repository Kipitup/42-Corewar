/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 15:08:34 by cbretagn          #+#    #+#             */
/*   Updated: 2020/05/24 14:39:53 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	ft_fork(t_vm *vm, t_cursor *cur)
{
	short	index;

	index = get_mem(vm, cur->pc + 1, 2);
	create_new_cursor(vm, cur);
	vm->cursor->pc = (cur->pc + (index % IDX_MOD)) % MEM_SIZE;
	cur->pc = (cur->pc + 3) % MEM_SIZE;
}

void	ft_lfork(t_vm *vm, t_cursor *cur)
{
	short	index;

	index = get_mem(vm, cur->pc + 1, 2);
	create_new_cursor(vm, cur);
	vm->cursor->pc = (cur->pc + index) % MEM_SIZE;
	cur->pc = (cur->pc + 3) % MEM_SIZE;
}