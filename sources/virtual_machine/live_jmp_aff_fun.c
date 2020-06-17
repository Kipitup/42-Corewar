/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_jmp_aff_fun.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:20:43 by ssfar             #+#    #+#             */
/*   Updated: 2020/06/17 02:54:21 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	ft_live(t_vm *vm, t_cursor *cur)
{
	int	live_id;

	live_id = get_mem(vm, cur->pc, 1, 4);
	cur->pc = (cur->pc + 5) % MEM_SIZE;
	cur->live = true;
	if (-live_id > 0 && -live_id <= vm->nb_player)
	{
		if (vm->visualiser != true)
		{
			ft_printf("A process shows that player %d (%s) is alive\n",
				-live_id, vm->player[-live_id - 1].prog_name);
		}
		vm->last_reported_alive = live_id;
		vm->live_counter++;
		if (vm->live_counter == NBR_LIVE)
			vm->nbr_live_reached = true;
	}
}

void	ft_zjmp(t_vm *vm, t_cursor *cur)
{
	short	jump;

	if (cur->carry != 1)
		cur->pc = (cur->pc + 3) % MEM_SIZE;
	else
	{
		jump = get_mem(vm, cur->pc, 1, 2);
		cur->pc = (cur->pc + jump % IDX_MOD) % MEM_SIZE;
	}
}

void	ft_aff(t_vm *vm, t_cursor *cur)
{
	unsigned char	arg[3];

	get_ocp(vm, cur->pc + 1, arg);
	if (check_param(arg, REG_ONLY, 0, 0)
		&& is_reg(vm->arena[(cur->pc + 2) % MEM_SIZE]))
		ft_printf("Aff: %c\n", get_reg(vm, cur, cur->pc + 2) % 256);
	cur->pc = (cur->pc + 3) % MEM_SIZE;
}
