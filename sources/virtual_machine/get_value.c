/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <samisfar.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:20:14 by ssfar             #+#    #+#             */
/*   Updated: 2020/07/24 12:46:36 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

unsigned int	get_mem(t_vm *vm, unsigned long long pc, long long pos,
	int size)
{
	unsigned int	ret;
	unsigned int	mult;

	ret = 0;
	mult = 1;
	pos = pos % IDX_MOD;
	while (--size >= 0)
	{
		ret = ret + vm->arena[(pc + pos + size) % MEM_SIZE] * mult;
		mult *= 256;
	}
	return (ret);
}

/*
** Read 4 bytes from memory arena at as they are, ignoring the endiannes
*/

unsigned int	read_int(t_vm *vm, unsigned long long pc, long long pos)
{
	unsigned int	ret;
	int				i;
	unsigned char	*p;

	p = (unsigned char *)&ret;
	i = 0;
	pos = pos % IDX_MOD;
	while (i < 4)
	{
		p[i] = vm->arena[(pc + pos) % MEM_SIZE];
		pos++;
		i++;
	}
	return (ret);
}

/*
** Write (value) byte per byte inside memory arena at ((pc) + (pos)) % MEM_SIZE.
*/

void			write_int(t_vm *vm, unsigned int value, unsigned long long pc,
	long long pos)
{
	int				i;
	unsigned char	*p;

	p = (unsigned char*)&value;
	i = 0;
	pos = pos % IDX_MOD;
	while (i < 4)
	{
		vm->arena[(pc + pos) % MEM_SIZE] = p[i];
		pos++;
		i++;
	}
}
