/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 21:49:33 by vrobin            #+#    #+#             */
/*   Updated: 2020/06/18 15:23:29 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	refresh_window(t_vm *vm)
{
	wrefresh(vm->window->memory);
	wrefresh(vm->window->info1);
	wrefresh(vm->window->champions);
	wrefresh(vm->window->info2);
	wrefresh(vm->window->input);
	refresh();
}

int		get_visu_input(t_vm *vm, int ch)
{
	if (ch == 'c')
	{
		ch = getch();
		if (ch != 'q')
			return (ch);
	}
	if (ch == 'q')
	{
		free_all(vm);
		system("clear");
		exit(0);
	}
	nodelay(vm->window->memory, 1);
	if (ch != 'c')
		ch = wgetch(vm->window->memory);
	if (ch == ' ')
	{
		mvwprintw(vm->window->input, 1, 1, "Pause \t\t\t[SPACE]");
		refresh_window(vm);
		ch = wgetch(vm->window->memory);
		while (ch != ' ' && ch != 'c' && ch != 'q')
			ch = wgetch(vm->window->memory);
	}
	return (ch);
}
