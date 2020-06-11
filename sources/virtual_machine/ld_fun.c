/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_fun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <cbretagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 17:39:49 by cbretagn          #+#    #+#             */
/*   Updated: 2020/06/04 17:26:50 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	ft_ld(t_vm *vm, t_cursor *cur)
{
	unsigned char	arg[4];
	unsigned int	value;

	get_ocp(vm, cur->pc + 1, arg);
	if (check_param(arg, DIR_IND, REG_ONLY, 0)
		&& is_reg(vm->arena[(cur->pc + 2 + arg_size(arg[0], true)) % MEM_SIZE]))
	{
		if (arg[0] == DIR_CODE)
			value = read_int(vm, cur->pc + 2);
		else
			value = read_int(vm, cur->pc
				+ (short)get_mem(vm, cur->pc + 2, 2) % IDX_MOD);
		cur->reg[vm->arena[(cur->pc + 2 + arg_size(arg[0], true))
			% MEM_SIZE] - 1] = value;
		cur->carry = value ? 0 : 1;
	}
	cur->pc = (cur->pc + 2 + jump(arg, true)) % MEM_SIZE;
}

void	ft_lld(t_vm *vm, t_cursor *cur)
{
	unsigned char	arg[4];
	unsigned int	value;

	get_ocp(vm, cur->pc + 1, arg);
	if (check_param(arg, DIR_IND, REG_ONLY, 0)
		&& is_reg(vm->arena[(cur->pc + 2 + arg_size(arg[0], true)) % MEM_SIZE]))
	{
		if (arg[0] == DIR_CODE)
			value = read_int(vm, cur->pc + 2);
		else
			value = read_h(vm, cur->pc
				+ (short)get_mem(vm, cur->pc + 2, 2));
		cur->reg[vm->arena[(cur->pc + 2 + arg_size(arg[0], true))
			% MEM_SIZE] - 1] = value;
		cur->carry = value ? 0 : 1;
	}
	cur->pc = (cur->pc + 2 + jump(arg, true)) % MEM_SIZE;
}

void	ft_ldi(t_vm *vm, t_cursor *cur)
{
	unsigned char	arg[4];
	int	val;

	get_ocp(vm, cur->pc + 1, arg);
	if (check_param(arg, ALL, REG_DIR, REG_ONLY)
		&& check_reg(vm, arg[0], cur->pc + 2)
		&& check_reg(vm, arg[1], cur->pc + 2 + arg_size(arg[0], false))
		&& is_reg(vm->arena[(cur->pc + 1 + jump(arg, false)) % MEM_SIZE]))
	{
		if (arg[0] == REG_CODE)
			val = get_reg(vm, cur, cur->pc + 2);
		else if (arg[0] == DIR_CODE)
			val = (short)get_mem(vm, cur->pc + 2, 2);
		else
			val = get_mem(vm, cur->pc + (short)get_mem(vm, cur->pc + 2, 2)
				% IDX_MOD, 4);
		if (arg[1] == REG_CODE)
			val += get_reg(vm, cur, cur->pc + 2 + arg_size(arg[0], false));
		else
			val += (short)get_mem(vm, cur->pc + 2 + arg_size(arg[0], 0), 2);
		val = read_int(vm, cur->pc + val % IDX_MOD);
		cur->reg[vm->arena[(cur->pc + 1 + jump(arg, 0)) % MEM_SIZE] - 1] = val;
		cur->carry = val ? 0 : 1;
	}
	cur->pc = (cur->pc + 2 + jump(arg, false)) % MEM_SIZE;
}

void	ft_lldi(t_vm *vm, t_cursor *cur)
{
	unsigned char	arg[4];
	int	val;

	get_ocp(vm, cur->pc + 1, arg);
	if (check_param(arg, ALL, REG_DIR, REG_ONLY)
		&& check_reg(vm, arg[0], cur->pc + 2)
		&& check_reg(vm, arg[1], cur->pc + 2 + arg_size(arg[0], false))
		&& is_reg(vm->arena[(cur->pc + 1 + jump(arg, false)) % MEM_SIZE]))
	{
		if (arg[0] == REG_CODE)
			val = get_reg(vm, cur, cur->pc + 2);
		else if (arg[0] == DIR_CODE)
			val = (short)get_mem(vm, cur->pc + 2, 2);
		else
			val = get_mem(vm, cur->pc + (short)get_mem(vm, cur->pc + 2, 2), 4);
		if (arg[1] == REG_CODE)
			val += get_reg(vm, cur, cur->pc + 2 + arg_size(arg[0], false));
		else
			val += (short)get_mem(vm, cur->pc + 2 + arg_size(arg[0], 0), 2);
		val = read_int(vm, cur->pc + val);
		cur->reg[vm->arena[(cur->pc + 2 + arg_size(arg[0], false)
			+ arg_size(arg[1], false)) % MEM_SIZE] - 1] = val;
		cur->carry = val ? 0 : 1;
	}
	cur->pc = (cur->pc + 2 + jump(arg, false)) % MEM_SIZE;
}
