/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 14:35:25 by ssfar             #+#    #+#             */
/*   Updated: 2020/04/17 14:35:25 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VM_H
# define COREWAR_VM_H

# include "ft_printf.h"
# include "libft.h"
# include "op.h"
# include <errno.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_cursor
{
	//int			id;
	t_bool			carry;
	unsigned char	opcode;
	unsigned int	last_live;
	unsigned int	wait_cylces;
	unsigned short	pc;
	unsigned short	jump;
	int				registries[REG_NUMBER];
	struct s_cursor	*next;	
}					t_cursor;

/*
**	info of a processus
*/

typedef struct		s_player
{
	char			*file;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_player;

/*
** info from .cor file
*/

typedef struct		s_vm
{
	t_player		*player;
	t_cursor		*cursor;
	unsigned char	arena[MEM_SIZE];
	int				option_id;
	int				nb_player;
	unsigned int	cycle_counter;
	unsigned int	live_counter;
	unsigned int	dump;
	t_bool			visualiser;
}					t_vm;

/*
**
*/

void	create_new_cursor(t_vm *vm, t_cursor *parent);
void	read_player_file(t_vm *vm);
void	check_file(t_vm *vm, int fd, int i);
void	check_for_null_bytes(t_vm *vm, int fd, unsigned int i);
void	u_big_endian_to_u(unsigned int *big_endian);
void	u_little_endian_to_u(unsigned int *little_endian);
void	corewar_vm(int ac, char **av);
void	init(int ac, char **av, t_vm *vm);
void	complete_player_id(int ac, char **av, t_vm *vm);
void	exit_failure(char *error_message, char *file, t_bool call_perror);
void	dump(t_vm *vm);
void	print_player(t_vm *vm);
void	parsing(int ac, char **av, t_vm *vm);
void	count_player(int ac, char **av, t_vm *vm);
void	get_option_id(int ac, char **av, int *i, t_vm *vm);
void	get_dump_cycle(int ac, char **av, int *i, t_vm *vm);
void	set_option_id(char **av, int i, t_vm *vm);

#endif
