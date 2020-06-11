/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <cbretagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:20:14 by ssfar             #+#    #+#             */
/*   Updated: 2020/06/04 17:26:58 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

unsigned int	get_mem(t_vm *vm, unsigned long long pos, int size)
{
	unsigned int	ret;
	unsigned int	mult;

	ret = 0;
	mult = 1;
	while (--size >= 0)
	{
		ret = ret + vm->arena[(pos + size) % MEM_SIZE] * mult;
		mult *= 256;
	}
	return (ret);
}

/*
** The function bellow read/write the values as they are, ignoring the endiannes
*/

unsigned int	read_int(t_vm *vm, unsigned long long pos)
{
	unsigned int	ret;
	int		i;
	unsigned char	*p;

	p = (unsigned char *)&ret;
	i = 0;
	while (i < 4)
	{
		p[i] = vm->arena[pos % MEM_SIZE];
		pos++;
		i++;
	}
	return (ret);
}

unsigned int	read_h(t_vm *vm, unsigned long long pos)
{
	unsigned int	ret;
	unsigned char	*p;

	p = (unsigned char *)&ret;
	p[0] = 0;
	p[1] = 0;
	p[2] = vm->arena[pos % MEM_SIZE];
	p[3] = vm->arena[(pos + 1) % MEM_SIZE];
	return (ret);
}

void	write_h(t_vm *vm, unsigned short value, unsigned long long pos)
{
	int				i;
	unsigned char	*p;

	p = (unsigned char*)&value;
	i = 0;
	while (i < 2)
	{
		vm->arena[pos % MEM_SIZE] = p[i];
		pos++;
		i++;
	}
}

void	write_int(t_vm *vm, unsigned int value, unsigned long long pos)
{
	int				i;
	unsigned char	*p;

	p = (unsigned char*)&value;
	i = 0;
	while (i < 4)
	{
		vm->arena[pos % MEM_SIZE] = p[i];
		pos++;
		i++;
	}
}