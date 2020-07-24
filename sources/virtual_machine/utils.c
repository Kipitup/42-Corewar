/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <samisfar.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:14:54 by ssfar             #+#    #+#             */
/*   Updated: 2020/07/24 14:59:57 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

/*
** Check if the type of parameter (code) is authorised related to (allowed).
*/

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

/*
** Check if all the parameters from (arg) tab correspond to the possible ones
** (p0), (p1)...
*/

t_bool			check_param(unsigned char *arg, int p0, int p1, int p2)
{
	return (check_one(arg[0], p0) && check_one(arg[1], p1)
		&& check_one(arg[2], p2));
}

/*
** Return the addition of all the argument size from the argument of (arg) tab.
** big_dir = 1 for 4 bytes long direct parameters.
** bir_dir = 0 for 2 bytes long direct parameters.
*/

int				jump(unsigned char *arg, t_bool big_dir)
{
	return (arg_size(arg[0], big_dir) + arg_size(arg[1], big_dir)
		+ arg_size(arg[2], big_dir));
}

/*
** Return the adition of all the arguments size.
** big_dir = 1 for 4 bytes long direct parameters.
** bir_dir = 0 for 2 bytes long direct parameters.
*/

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

/*
** Read the byte at arena[(pos) % MEM_SIZE] suposed to describe the folowing
** argument types and separate each types into (tab) array.
*/

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
