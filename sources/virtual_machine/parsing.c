/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 15:56:23 by ssfar             #+#    #+#             */
/*   Updated: 2020/06/18 16:57:17 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	parsing(int ac, char **av, t_vm *vm)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strlen(av[i]) > 4
			&& ft_strcmp(&(av[i][ft_strlen(av[i]) - 4]), ".cor") == 0)
			set_option_id(av, i, vm);
		else if (ft_strcmp(av[i], "-n") == 0)
			get_option_id(ac, av, &i, vm);
		else if (ft_strcmp(av[i], "-v") == 0)
			vm->visualiser = true;
		else if (ft_strcmp(av[i], "-dump") == 0)
			get_cycle_to_dump(ac, av, &i, vm);
		else
			exit_failure(vm, "Usage : ./corewar "
			"[-dump nbr_cycles] [[-n number] champion1.cor] ...", NULL, false);
		i++;
	}
}

void	count_player(int ac, char **av, t_vm *vm)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strlen(av[i]) > 4
				&& ft_strcmp(&(av[i][ft_strlen(av[i]) - 4]), ".cor") == 0)
		{
			vm->nb_player++;
			if (vm->nb_player < 1 || vm->nb_player > MAX_PLAYERS)
				exit_failure(vm, "Too many players", NULL, false);
		}
		i++;
	}
	if (vm->nb_player < 1)
		exit_failure(vm, "Usage : ./corewar "
		"[-dump nbr_cycles] [[-n number] champion1.cor] ...", NULL, false);
}

void	get_option_id(int ac, char **av, int *i, t_vm *vm)
{
	(*i)++;
	if (*i == ac || vm->option_id != 0)
		exit_failure(vm, "Usage : ./corewar "
		"[-dump nbr_cycles] [[-n number] champion1.cor] ...", NULL, false);
	if (atoi_overflow(av[*i], &(vm->option_id)))
		exit_failure(vm, "Player -n number is too big", NULL, false);
	if (vm->option_id < 1 || vm->option_id > vm->nb_player)
		exit_failure(vm, "Player -n number must be between 1 and the ammount "
		"of files", NULL, false);
}

/*
** Get the option -n value and verify if it's a valid number **
*/

void	get_cycle_to_dump(int ac, char **av, int *i, t_vm *vm)
{
	(*i)++;
	if (*i == ac || vm->dump == true)
		exit_failure(vm, "Usage : ./corewar "
		"[-dump nbr_cycles] [[-n number] champion1.cor] ...", NULL, false);
	if (!str_is_numeric_no_symbol(av[*i]))
		exit_failure(vm, "Dump cycle must be a non negative number", NULL, 0);
	if (atoul_overflow(av[*i], &(vm->cycle_to_dump)))
		exit_failure(vm, "Dump cycle is too big", NULL, false);
	vm->dump = true;
}

void	set_option_id(char **av, int i, t_vm *vm)
{
	if (vm->option_id != 0)
	{
		if (vm->player[vm->option_id - 1].file != NULL)
			exit_failure(vm, "Same player ID can't be used twice", NULL, false);
		vm->player[vm->option_id - 1].file = av[i];
		vm->option_id = 0;
	}
}

/*
** Verify if the option -n value has already been used, if not, **
** store the name of the related file **
** inside an array where the index correspond to it's id - 1. **
*/
