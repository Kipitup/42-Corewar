/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 13:47:04 by ssfar             #+#    #+#             */
/*   Updated: 2020/06/18 16:11:15 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	dump(t_vm *vm)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("0x%04x : ", i);
		j = 0;
		while (j < 31)
		{
			ft_printf("%02x ", vm->arena[i]);
			i++;
			if (i == MEM_SIZE)
			{
				write(1, "\n", 1);
				free_all(vm);
				exit(0);
			}
			j++;
		}
		ft_printf("%02x\n", vm->arena[i]);
		i++;
	}
	free_all(vm);
	exit(0);
}

void	print_player(t_vm *vm)
{
	int	i;

	if (vm->visualiser != true)
	{
		ft_printf("Introducing contestants...\n");
		i = 0;
		while (i < vm->nb_player)
		{
			ft_printf("* Player %u, ", i + 1);
			ft_printf("weighing %u bytes, ", vm->player[i].prog_size);
			ft_printf("\"%s\" ", vm->player[i].prog_name);
			ft_printf("(\"%s\") !\n", vm->player[i].comment);
			i++;
		}
	}
}

void	print_winner(t_vm *vm)
{
	if (vm->visualiser == true)
	{
		mvwprintw(vm->window->input, 1, 1, "Press any key to exit !");
		wrefresh(vm->window->input);
		getch();
		endwin();
	}
	ft_printf("Player %d ", -vm->last_reported_alive);
	ft_printf("(%s) won\n", vm->player[-vm->last_reported_alive - 1].prog_name);
}
