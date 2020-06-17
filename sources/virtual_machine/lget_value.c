/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lget_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 02:10:29 by ssfar             #+#    #+#             */
/*   Updated: 2020/06/17 02:10:29 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

unsigned int	lget_mem(t_vm *vm, unsigned long long pc,
	long long pos, int size)
{
	unsigned int	ret;
	unsigned int	mult;

	ret = 0;
	mult = 1;
	while (--size >= 0)
	{
		ret = ret + vm->arena[(pc + pos + size) % MEM_SIZE] * mult;
		mult *= 256;
	}
	return (ret);
}

/*
** The function bellow read/write the values as they are, ignoring the endiannes
*/

unsigned int	lread_int(t_vm *vm, unsigned long long pc,
	long long pos)
{
	unsigned int	ret;
	int		i;
	unsigned char	*p;

	p = (unsigned char *)&ret;
	i = 0;
	while (i < 4)
	{
		p[i] = vm->arena[(pc + pos) % MEM_SIZE];
		pos++;
		i++;
	}
	return (ret);
}

unsigned int	lread_h(t_vm *vm, unsigned long long pc, long long pos)
{
	unsigned int	ret;
	unsigned char	*p;

	p = (unsigned char *)&ret;
	p[2] = vm->arena[(pc + pos) % MEM_SIZE];
	p[3] = vm->arena[(pc + pos + 1) % MEM_SIZE];
	if (p[2] > 127)
	{
		p[0] = 255;
		p[1] = 255;
	}
	else
	{
		p[0] = 0;
		p[1] = 0;
	}
	return (ret);
}
