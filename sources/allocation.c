
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
		new_cursor->jump = 0;
		new_cursor->opcode = 0;
		// ...
	}
	new_cursor->next = vm->cursor;
	vm->cursor = new_cursor;
}
