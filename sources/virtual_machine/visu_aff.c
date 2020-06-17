/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_aff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <vrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 21:24:12 by vrobin            #+#    #+#             */
/*   Updated: 2020/06/17 21:52:27 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	aff_memory(t_vm *vm)
{
	size_t	j;
	size_t	i;

	j = 0;
	while (j < 64)
	{
		i = 0;
		while (i < 64)
		{
			wattron(vm->window->memory,
			COLOR_PAIR(vm->arena_color[i + j * 64]));
			mvwprintw(vm->window->memory, j, i * 3,
			"%c%02x", ' ', vm->arena[i + j * 64]);
			wattroff(vm->window->memory,
			COLOR_PAIR(vm->arena_color[i + j * 64]));
			i++;
		}
		j++;
	}
	wrefresh(vm->window->memory);
	reset_light(vm);
}

void	aff_input(t_vm *vm)
{
	size_t	j;

	j = 1;
	mvwprintw(vm->window->input, j, 1, "Play \t\t\t[SPACE]");
	j += 2;
	mvwprintw(vm->window->input, j, 1, "Next Turn \t\t[c]");
	j += 2;
	mvwprintw(vm->window->input, j, 1, "Leave \t\t\t[q]");
}

void	aff_info(t_vm *vm)
{
	size_t	j;

	j = 1;
	mvwprintw(vm->window->info1, j, 1, "Cycle:\t\t\t%d\t", vm->cycle_counter);
	j += 2;
	mvwprintw(vm->window->info1, j, 1, "Players:\t\t%d", vm->nb_player);
	j += 2;
	mvwprintw(vm->window->info1, j, 1,
	"Last alive:\t\tPlayer %d", -1 * vm->last_reported_alive);
	j = 1;
	mvwprintw(vm->window->info2, j, 1,
	"Cycle to die:\t\t%d\t", vm->cycle_to_die);
	j += 2;
	mvwprintw(vm->window->info2, j, 1, "Checks:\t\t%d\t", vm->check_counter);
	j += 2;
	mvwprintw(vm->window->info2, j, 1, "Lives:\t\t\t%d\t", vm->live_counter);
}

void	aff_champions(t_vm *vm)
{
	int		i;
	size_t	j;

	i = 0;
	j = 1;
	while (i < vm->nb_player)
	{
		wattron(vm->window->champions, COLOR_PAIR(i + 1 + vm->nb_player));
		mvwprintw(vm->window->champions, j, 1, "Player %d:", i + 1);
		j += 2;
		mvwprintw(vm->window->champions, j, 1, "%s", vm->player[i].prog_name);
		j += 4;
		wattroff(vm->window->champions, COLOR_PAIR(i + 1 + vm->nb_player));
		i++;
	}
}

void	display_round(t_vm *vm)
{
	aff_memory(vm);
	aff_info(vm);
	aff_champions(vm);
	aff_input(vm);
	refresh_window(vm);
}
