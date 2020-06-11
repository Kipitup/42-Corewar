/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:13:55 by ssfar             #+#    #+#             */
/*   Updated: 2020/05/24 19:21:25 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	load_function(t_vm *vm)
{
	vm->tab[1] = ft_live;
	vm->tab[2] = ft_ld;
	vm->tab[3] = ft_st;
	vm->tab[4] = ft_add;
	vm->tab[5] = ft_sub;
	vm->tab[6] = ft_and;
	vm->tab[7] = ft_or;
	vm->tab[8] = ft_xor;
	vm->tab[9] = ft_zjmp;
	vm->tab[10] = ft_ldi;
	vm->tab[11] = ft_sti;
	vm->tab[12] = ft_fork;
	vm->tab[13] = ft_lld;
	vm->tab[14] = ft_lldi;
	vm->tab[15] = ft_lfork;
	vm->tab[16] = ft_aff;
}

void	load_cost(t_vm *vm)
{
	vm->cost[0] = 1;
	vm->cost[1] = 10;
	vm->cost[2] = 5;
	vm->cost[3] = 5;
	vm->cost[4] = 10;
	vm->cost[5] = 10;
	vm->cost[6] = 6;
	vm->cost[7] = 6;
	vm->cost[8] = 6;
	vm->cost[9] = 20;
	vm->cost[10] = 25;
	vm->cost[11] = 25;
	vm->cost[12] = 800;
	vm->cost[13] = 10;
	vm->cost[14] = 50;
	vm->cost[15] = 1000;
	vm->cost[16] = 2;
}
