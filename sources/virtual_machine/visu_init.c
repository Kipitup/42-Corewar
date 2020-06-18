/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 21:49:12 by vrobin            #+#    #+#             */
/*   Updated: 2020/06/18 16:44:40 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

t_window	*init_window(t_vm *vm, t_window *window)
{
	WINDOW * memory;
	WINDOW * info1;
	WINDOW * info2;
	WINDOW * champions;
	WINDOW * input;
	memory = NULL;
	info1 = NULL;
	info2 = NULL;
	champions = NULL;
	input = NULL;
	if (!(window = malloc(sizeof(t_window))))
	{
		endwin();
		exit_failure(vm, "Malloc Error", NULL, false);
	}
	window->memory = memory;
	window->info1 = info1;
	window->info2 = info2;
	window->champions = champions;
	window->input = input;
	return (window);
}

void		init_color_arena(t_vm *vm)
{
	int	i;

	i = 0;
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	pair_colors(vm);
	while (i < MEM_SIZE)
	{
		vm->arena_color[i] = 0;
		i++;
	}
	i = 0;
	while (i < vm->nb_player)
	{
		color_player(vm, i + 1, vm->player[i].prog_size, vm->nb_player);
		i++;
	}
}

void		set_window(t_vm *vm, size_t y, size_t ymax, size_t xmax)
{
	size_t x;

	x = 192;
	vm->window->memory = newwin(y + 1, x + 1, 0, 0);
	vm->window->info1 = newwin(9, 75, 0, xmax - 75);
	vm->window->champions = newwin(50 - 12.5, 75, 9, xmax - 75);
	vm->window->input = newwin(11, 75, ymax - 22, xmax - 75);
	vm->window->info2 = newwin(11, 75, ymax - 11, xmax - 75);
	init_color_arena(vm);
	display_round(vm);
	display_round(vm);
	mvwprintw(vm->window->input, 1, 1, "Pause \t\t\t[SPACE]");
	refresh_window(vm);
}

int			init_visu(t_vm *vm)
{
	size_t		ymax;
	size_t		xmax;
	size_t		y;
	size_t		x;
	t_window	*window;

	initscr();
	start_color();
	noecho();
	cbreak();
	getmaxyx(stdscr, ymax, xmax);
	if (ymax < 64 || xmax < 250)
	{
		endwin();
		ft_printf("ERROR, SCREEN TO SHORT, ZOOM OUT\n");
		free_all(vm);
		exit(-1);
	}
	window = NULL;
	y = ymax;
	x = 192;
	vm->window = init_window(vm, window);
	set_window(vm, y, ymax, xmax);
	return (0);
}
