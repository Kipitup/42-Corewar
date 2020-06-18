/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   registry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 15:36:47 by ssfar             #+#    #+#             */
/*   Updated: 2020/06/18 16:21:15 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

t_bool			is_reg(unsigned char reg)
{
	if (reg < 1 || reg > REG_NUMBER)
		return (false);
	return (true);
}

t_bool			check_reg(t_vm *vm, unsigned char type, unsigned long long pos)
{
	if (type == REG_CODE && !(is_reg(vm->arena[pos % MEM_SIZE])))
		return (false);
	return (true);
}

t_bool			check_3reg(t_vm *vm, t_cursor *cur, unsigned char *arg,
					t_bool big_dir)
{
	if (check_reg(vm, arg[0], cur->pc + 2)
		&& check_reg(vm, arg[1], cur->pc + 2 + arg_size(arg[0], big_dir))
		&& check_reg(vm, arg[2], cur->pc + 2 + arg_size(arg[0], big_dir)
		+ arg_size(arg[1], big_dir)))
		return (true);
	return (false);
}

unsigned int	get_reg(t_vm *vm, t_cursor *cur, unsigned long long pos)
{
	unsigned int	ret;
	unsigned char	*p;
	unsigned int	mult;

	mult = 256;
	p = (unsigned char *)&(cur->reg[vm->arena[pos % MEM_SIZE] - 1]);
	ret = p[0] * mult * mult * mult + p[1] * mult * mult + p[2] * mult + p[3];
	return (ret);
}

void			cpy_to_reg(unsigned int *reg, unsigned int value)
{
	unsigned int	tmp;
	unsigned char	*p;

	p = (unsigned char *)reg;
	tmp = value / (256 * 256 * 256);
	p[0] = (unsigned char)tmp;
	value = value - tmp * 256 * 256 * 256;
	tmp = value / (256 * 256);
	p[1] = (unsigned char)tmp;
	value -= tmp * 256 * 256;
	tmp = value / 256;
	p[2] = (unsigned char)tmp;
	value -= tmp * 256;
	p[3] = (unsigned char)value;
}
