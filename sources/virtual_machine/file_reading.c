/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:59:06 by ssfar             #+#    #+#             */
/*   Updated: 2020/04/25 17:59:06 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	read_player_file(t_vm *vm)
{
	int				fd;
	int				i;
	unsigned int	tmp;
	unsigned char	code_buf[CHAMP_MAX_SIZE];
	ssize_t			ret;

	i = 0;
	while (i < vm->nb_player)
	{
		if ((fd = open(vm->player[i].file, O_RDONLY)) == -1)
			exit_failure("Open", NULL, true);
		check_file(vm, fd, i);
		if ((ret = read(fd, code_buf, vm->player[i].prog_size)) == -1)
			exit_failure("Read", NULL, true);
		if (ret != vm->player[i].prog_size)
			exit_failure("%s is not well formated", vm->player[i].file, false);
		if ((ret = read(fd, &tmp, 1)) == -1)
			exit_failure("Read", NULL, true);
		if (ret != 0)
			exit_failure("%s is not well formated", vm->player[i].file, false);
		load_champion_code(vm, code_buf, vm->player[i].prog_size);
		close(fd);
		i++;
	}
}

void	check_file(t_vm *vm, int fd, int i)
{
	ssize_t			ret;
	unsigned int	tmp;

	if ((ret = read(fd, &tmp, 4)) == -1)
		exit_failure("Read", NULL, true);
	u_big_endian_to_u(&tmp);
	if (tmp != (COREWAR_EXEC_MAGIC))
		exit_failure("Invalid magic header in %s", vm->player[i].file, false);
	if ((ret = read(fd, vm->player[i].prog_name, PROG_NAME_LENGTH)) == -1)
		exit_failure("Read", NULL, true);
	vm->player[i].prog_name[PROG_NAME_LENGTH] = '\0';
	check_for_null_bytes(vm, fd, i);
	if ((ret = read(fd, &vm->player[i].prog_size, 4)) == -1)
		exit_failure("read", NULL, true);
	u_big_endian_to_u(&vm->player[i].prog_size);
	if (vm->player[i].prog_size > CHAMP_MAX_SIZE)
		exit_failure("%s program size is too big", vm->player[i].file, false);
	if ((ret = read(fd, vm->player[i].comment, COMMENT_LENGTH)) == -1)
		exit_failure("read", NULL, true);
	vm->player[i].comment[COMMENT_LENGTH] = '\0';
	check_for_null_bytes(vm, fd, i);
	create_new_cursor(vm, NULL);
	cpy_to_reg(&(vm->cursor->reg[0]), -i -1);
	vm->cursor->pc = (MEM_SIZE / vm->nb_player) * i;
	vm->cursor->player_id = i + 1;
}

void	check_for_null_bytes(t_vm *vm, int fd, unsigned int i)
{
	unsigned int	tmp;
	ssize_t			ret;

	if ((ret = read(fd, &tmp, 4)) == -1)
			exit_failure("Read", NULL, true);
		if (tmp != 0)
			exit_failure("%s is not well formated", vm->player[i].file, false);
}

void	load_champion_code(t_vm *vm, unsigned char *champion_code, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		vm->arena[(vm->cursor->pc + j) % MEM_SIZE] = champion_code[j];
		j++;
	}
}

void	u_big_endian_to_u(unsigned int *b_endian)
{
	unsigned char *p;

	p = (unsigned char*)b_endian;
	*b_endian = p[0] * 256 * 256 * 256 + p[1] * 256 * 256 + p[2] * 256 + p[3];
}

/*
** Store the big endian value of an unsigned int on the current endiannes.
*/
