
#include "corewar_vm.h"

void	create_new_cursor(t_vm *vm, t_cursor *parent)
{
	t_cursor	*tmp_cursor;

	if (!(tmp_cursor = malloc(sizeof(*tmp_cursor))))
		exit_failure("Malloc Error", NULL, false);
	tmp_cursor->next = vm->cursor;
	vm->cursor = tmp_cursor;
	if (parent != NULL)
		*tmp_cursor = *parent; 
	else
	{
		tmp_cursor->carry = false;
		tmp_cursor->wait_cylces = 0;
		// ...
	}
}
