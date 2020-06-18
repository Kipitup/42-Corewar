/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:14:54 by ssfar             #+#    #+#             */
/*   Updated: 2020/06/18 02:01:40 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

t_bool			check_one(unsigned char code, int allowed)
{
	if (allowed == ALL && code == 0)
		return (false);
	if (allowed == REG_ONLY && code != REG_CODE)
		return (false);
	if (allowed == DIR_ONLY && code != DIR_CODE)
		return (false);
	if (allowed == IND_ONLY && code != IND_CODE)
		return (false);
	if (allowed == REG_DIR && !(code == REG_CODE || code == DIR_CODE))
		return (false);
	if (allowed == REG_IND && !(code == REG_CODE || code == IND_CODE))
		return (false);
	if (allowed == DIR_IND && !(code == DIR_CODE || code == IND_CODE))
		return (false);
	return (true);
}

t_bool			check_param(unsigned char *arg, int p0, int p1, int p2)
{
	return (check_one(arg[0], p0) && check_one(arg[1], p1)
		&& check_one(arg[2], p2));
}

int				jump(unsigned char *arg, t_bool big_dir)
{
	return (arg_size(arg[0], big_dir) + arg_size(arg[1], big_dir)
		+ arg_size(arg[2], big_dir));
}

unsigned int	arg_size(unsigned char arg, t_bool big_dir)
{
	if (arg == 0)
		return (0);
	if (arg == REG_CODE)
		return (1);
	if (arg == IND_CODE)
		return (2);
	return (big_dir ? 4 : 2);
}

void			get_ocp(t_vm *vm, unsigned long long pos, unsigned char *tab)
{
	unsigned char	ocp;
	unsigned char	tmp;

	ocp = vm->arena[pos % MEM_SIZE];
	tmp = ocp & 192;
	tmp = tmp >> 6;
	tab[0] = tmp;
	tmp = ocp & 48;
	tmp = tmp >> 4;
	tab[1] = tmp;
	tmp = ocp & 12;
	tmp = tmp >> 2;
	tab[2] = tmp;
}
