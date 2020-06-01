/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 17:20:45 by ssfar             #+#    #+#             */
/*   Updated: 2020/05/22 17:20:45 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	create_new_cursor(t_vm *vm, t_cursor *parent)
{
	t_cursor	*new_cursor;

	if (!(new_cursor = malloc(sizeof(*new_cursor))))
		exit_failure("Malloc Error", NULL, false);
	if (parent != NULL)
		*new_cursor = *parent;
	else
	{
		new_cursor->carry = false;
		new_cursor->live = false;
		new_cursor->wait_cylces = 0;
		bzero(new_cursor->reg,
			REG_NUMBER * sizeof(*(new_cursor->reg)));
	}
	new_cursor->opcode = 0;
	new_cursor->next = vm->cursor;
	vm->cursor = new_cursor;
}
