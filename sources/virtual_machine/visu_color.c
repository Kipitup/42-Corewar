/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <vrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 21:39:31 by vrobin            #+#    #+#             */
/*   Updated: 2020/06/17 21:39:32 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	reset_light(t_vm *vm)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < 64)
	{
		i = 0;
		while (i < 64)
		{
			if (vm->arena_color[i + j * 64] > vm->nb_player)
				vm->arena_color[i + j * 64] -= vm->nb_player;
			i++;
		}
		j++;
	}
}

void	color_arena(t_vm *vm, t_cursor *cursor, unsigned long long pos)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		vm->arena_color[(pos % MEM_SIZE) + i] = cursor->player_id
		+ vm->nb_player;
		i++;
	}
}

void	color_player(t_vm *vm, size_t act_player, size_t size, size_t nb_player)
{
	int		i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	start = MEM_SIZE / nb_player;
	start = start * (act_player - 1);
	while (j < 64 && size > 0)
	{
		i = 0;
		while (i < 64 && size > 0)
		{
			if (i + j * 64 >= start && size > 0)
			{
				vm->arena_color[i + j * 64] = act_player;
				size--;
			}
			i++;
		}
		j++;
	}
}

void	pair_light_colors(t_vm *vm)
{
	int i;

	i = 1;
	init_pair(i + vm->nb_player, LIGHT_GREEN, COLOR_BLACK);
	i++;
	if (i <= vm->nb_player)
	{
		init_pair(i + vm->nb_player, LIGHT_BLUE, COLOR_BLACK);
		i++;
	}
	if (i <= vm->nb_player)
	{
		init_pair(i + vm->nb_player, LIGHT_RED, COLOR_BLACK);
		i++;
	}
	if (i <= vm->nb_player)
		init_pair(i + vm->nb_player, LIGHT_CYAN, COLOR_BLACK);
}

void	pair_colors(t_vm *vm)
{
	int i;

	i = 1;
	init_pair(i, COLOR_GREEN, COLOR_BLACK);
	i++;
	if (i <= vm->nb_player)
	{
		init_pair(i, COLOR_BLUE, COLOR_BLACK);
		i++;
	}
	if (i <= vm->nb_player)
	{
		init_pair(i, COLOR_RED, COLOR_BLACK);
		i++;
	}
	if (i <= vm->nb_player)
		init_pair(i, COLOR_CYAN, COLOR_BLACK);
	pair_light_colors(vm);
}
