/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <samisfar.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 14:11:29 by cbretagn          #+#    #+#             */
/*   Updated: 2020/07/24 12:11:27 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

/*
** Function usable by process (read 42 corewar pdf subject for more infos).
*/

void	ft_and(t_vm *vm, t_process *cur)
{
	unsigned char	arg[3];
	unsigned int	val;

	get_ocp(vm, cur->pc + 1, arg);
	if (check_param(arg, ALL, ALL, REG_ONLY) && check_3reg(vm, cur, arg, true))
	{
		if (arg[0] == REG_CODE)
			val = cur->reg[vm->arena[(cur->pc + 2) % MEM_SIZE] - 1];
		else if (arg[0] == DIR_CODE)
			val = read_int(vm, cur->pc, 2);
		else
			val = read_int(vm, cur->pc, (short)get_mem(vm, cur->pc, 2, 2));
		if (arg[1] == REG_CODE)
			val &= cur->reg[vm->arena[(cur->pc + 2 + arg_size(arg[0], true))
				% MEM_SIZE] - 1];
		else if (arg[1] == DIR_CODE)
			val &= read_int(vm, cur->pc, 2 + arg_size(arg[0], true));
		else
			val &= read_int(vm, cur->pc, (short)get_mem(vm, cur->pc, 2
				+ arg_size(arg[0], true), 2));
		cur->reg[vm->arena[(cur->pc + 1 + jump(arg, 1)) % MEM_SIZE] - 1] = val;
		cur->carry = val ? 0 : 1;
	}
	cur->pc = (cur->pc + 2 + jump(arg, true)) % MEM_SIZE;
}

/*
** Function usable by process (read 42 corewar pdf subject for more infos).
*/

void	ft_or(t_vm *vm, t_process *cur)
{
	unsigned char	arg[3];
	unsigned int	val;

	get_ocp(vm, cur->pc + 1, arg);
	if (check_param(arg, ALL, ALL, REG_ONLY) && check_3reg(vm, cur, arg, true))
	{
		if (arg[0] == REG_CODE)
			val = cur->reg[vm->arena[(cur->pc + 2) % MEM_SIZE] - 1];
		else if (arg[0] == DIR_CODE)
			val = read_int(vm, cur->pc, 2);
		else
			val = read_int(vm, cur->pc, (short)get_mem(vm, cur->pc, 2, 2));
		if (arg[1] == REG_CODE)
			val |= cur->reg[vm->arena[(cur->pc + 2 + arg_size(arg[0], true))
				% MEM_SIZE] - 1];
		else if (arg[1] == DIR_CODE)
			val |= read_int(vm, cur->pc, 2 + arg_size(arg[0], true));
		else
			val |= read_int(vm, cur->pc, (short)get_mem(vm, cur->pc, 2
				+ arg_size(arg[0], true), 2));
		cur->reg[vm->arena[(cur->pc + 1 + jump(arg, 1)) % MEM_SIZE] - 1] = val;
		cur->carry = val ? 0 : 1;
	}
	cur->pc = (cur->pc + 2 + jump(arg, true)) % MEM_SIZE;
}

/*
** Function usable by process (read 42 corewar pdf subject for more infos).
*/

void	ft_xor(t_vm *vm, t_process *cur)
{
	unsigned char	arg[3];
	unsigned int	val;

	get_ocp(vm, cur->pc + 1, arg);
	if (check_param(arg, ALL, ALL, REG_ONLY) && check_3reg(vm, cur, arg, true))
	{
		if (arg[0] == REG_CODE)
			val = cur->reg[vm->arena[(cur->pc + 2) % MEM_SIZE] - 1];
		else if (arg[0] == DIR_CODE)
			val = read_int(vm, cur->pc, 2);
		else
			val = read_int(vm, cur->pc, (short)get_mem(vm, cur->pc, 2, 2));
		if (arg[1] == REG_CODE)
			val ^= cur->reg[vm->arena[(cur->pc + 2 + arg_size(arg[0], true))
				% MEM_SIZE] - 1];
		else if (arg[1] == DIR_CODE)
			val ^= read_int(vm, cur->pc, 2 + arg_size(arg[0], true));
		else
			val ^= read_int(vm, cur->pc, (short)get_mem(vm, cur->pc, 2
				+ arg_size(arg[0], true), 2));
		cur->reg[vm->arena[(cur->pc + 1 + jump(arg, 1)) % MEM_SIZE] - 1] = val;
		cur->carry = val ? 0 : 1;
	}
	cur->pc = (cur->pc + 2 + jump(arg, true)) % MEM_SIZE;
}
