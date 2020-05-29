/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:58:01 by cbretagn          #+#    #+#             */
/*   Updated: 2020/05/27 23:23:34 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	ft_st(t_vm *vm, t_cursor *cur)
{
	unsigned char	arg[4];
	unsigned int	value;

	get_ocp(vm, cur->pc + 1, arg);
	if (check_param(arg, REG_ONLY, REG_IND, 0)
		&& is_reg(vm->arena[(cur->pc + 2) % MEM_SIZE])
		&& check_reg(vm, arg[1], cur->pc + 3))
	{
		value = cur->reg[vm->arena[(cur->pc + 2) % MEM_SIZE] - 1];
		if (arg[1] == REG_CODE)
			cur->reg[vm->arena[(cur->pc + 3) % MEM_SIZE] - 1] = value;
		else
		{
			write_int(vm, value,
				((short)get_mem(vm, cur->pc + 3, 2)) % IDX_MOD + cur->pc);
			// vm->visualiser == true ? color_arena(vm, cur) : 0;
		}
	}
	cur->pc = (cur->pc + 2 + jump(arg, true)) % MEM_SIZE;
}

void	ft_sti(t_vm *vm, t_cursor *cur)
{
	unsigned char	arg[4];
	unsigned int	value;
	int				pos[2];

	get_ocp(vm, cur->pc + 1, arg);
	if (check_param(arg, REG_ONLY, ALL, REG_DIR)
		&& is_reg(vm->arena[(cur->pc + 2) % MEM_SIZE])
		&& check_reg(vm, arg[1], cur->pc + 3)
		&& check_reg(vm, arg[2], cur->pc + 3 + arg_size(arg[1], false)))
	{
		value = cur->reg[vm->arena[(cur->pc + 2) % MEM_SIZE] - 1];
		if (arg[1] == REG_CODE)
			pos[0] = get_reg(vm, cur, cur->pc + 3);
		else
			pos[0] = (short)get_mem(vm, cur->pc + 3, 2);
		if (arg[1] == IND_CODE)
			pos[0] = get_mem(vm, cur->pc + pos[0], 4);
		if (arg[2] == REG_CODE)
			pos[1] = get_reg(vm, cur, cur->pc + 3 + arg_size(arg[1], 0));
		else
			pos[1] = (short)get_mem(vm, cur->pc + 3 + arg_size(arg[1], 0), 2);
		write_int(vm, value, cur->pc + (pos[0] + pos[1]) % IDX_MOD);
		// vm->visualiser == true ? color_arena(vm, cur) : 0;
	}
	cur->pc = (cur->pc + 2 + jump(arg, false)) % MEM_SIZE;
}