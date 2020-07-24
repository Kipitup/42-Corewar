/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sub_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <samisfar.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 18:09:13 by cbretagn          #+#    #+#             */
/*   Updated: 2020/07/24 12:10:53 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

/*
** Function usable by process (read 42 corewar pdf subject for more infos).
*/

void	ft_add(t_vm *vm, t_process *cur)
{
	unsigned char	arg[3];
	int				value;

	get_ocp(vm, cur->pc + 1, arg);
	if (check_param(arg, REG_ONLY, REG_ONLY, REG_ONLY)
		&& is_reg(vm->arena[(cur->pc + 2) % MEM_SIZE])
		&& is_reg(vm->arena[(cur->pc + 3) % MEM_SIZE])
		&& is_reg(vm->arena[(cur->pc + 4) % MEM_SIZE]))
	{
		value = get_reg(vm, cur, cur->pc + 2);
		value += get_reg(vm, cur, cur->pc + 3);
		cpy_to_reg(&(cur->reg[vm->arena[(cur->pc + 4) % MEM_SIZE] - 1]), value);
		cur->carry = value ? 0 : 1;
	}
	cur->pc = (cur->pc + 5) % MEM_SIZE;
}

/*
** Function usable by process (read 42 corewar pdf subject for more infos).
*/

void	ft_sub(t_vm *vm, t_process *cur)
{
	unsigned char	arg[3];
	int				value;

	get_ocp(vm, cur->pc + 1, arg);
	if (check_param(arg, REG_ONLY, REG_ONLY, REG_ONLY)
		&& is_reg(vm->arena[(cur->pc + 2) % MEM_SIZE])
		&& is_reg(vm->arena[(cur->pc + 3) % MEM_SIZE])
		&& is_reg(vm->arena[(cur->pc + 4) % MEM_SIZE]))
	{
		value = get_reg(vm, cur, cur->pc + 2);
		value -= get_reg(vm, cur, cur->pc + 3);
		cpy_to_reg(&(cur->reg[vm->arena[(cur->pc + 4) % MEM_SIZE] - 1]), value);
		cur->carry = value ? 0 : 1;
	}
	cur->pc = (cur->pc + 5) % MEM_SIZE;
}
