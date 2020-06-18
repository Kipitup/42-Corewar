/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 00:54:08 by ssfar             #+#    #+#             */
/*   Updated: 2020/06/18 17:07:34 by ssfar            ###   ########.fr       */
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
# include <ncurses.h>

# define ALL 7
# define DIR_IND 6
# define REG_IND 5
# define REG_DIR 4
# define IND_ONLY 3
# define DIR_ONLY 2
# define REG_ONLY 1

# define LIGHT_BLUE 12
# define LIGHT_GREEN 10
# define LIGHT_RED 9
# define LIGHT_CYAN 14

typedef struct	s_cursor
{
	t_bool				carry;
	t_bool				live;
	unsigned char		opcode;
	unsigned long long	wait_cylces;
	unsigned long long	pc;
	unsigned int		reg[REG_NUMBER];
	int					player_id;
	struct s_cursor		*next;
}				t_cursor;

/*
**	info of a processus
*/

typedef struct	s_player
{
	char				*file;
	unsigned char		prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	unsigned char		comment[COMMENT_LENGTH + 1];
}				t_player;

/*
** info from .cor file
*/

typedef struct	s_window
{
	WINDOW				*memory;
	WINDOW				*info1;
	WINDOW				*info2;
	WINDOW				*champions;
	WINDOW				*input;
}				t_window;

/*
** windows
*/

typedef struct	s_vm
{
	t_player			*player;
	t_cursor			*cursor;
	unsigned char		arena[MEM_SIZE];
	unsigned char		arena_color[MEM_SIZE];
	int					option_id;
	int					nb_player;
	int					last_reported_alive;
	t_bool				nbr_live_reached;
	unsigned long long	live_counter;
	unsigned long long	check_counter;
	unsigned long long	cycle_counter;
	unsigned long long	cycle_to_die;
	unsigned long long	cycle_to_dump;
	t_bool				visualiser;
	t_bool				dump;
	void				(*tab[17])(struct s_vm *vm, t_cursor *cur);
	unsigned int		cost[17];
	t_window			*window;
}				t_vm;

void			create_new_cursor(t_vm *vm, t_cursor *parent);
void			free_cursor_list(t_vm *vm);
void			free_all(t_vm *vm);
void			read_player_file(t_vm *vm);
void			check_file(t_vm *vm, int fd, int i);
void			check_for_null_bytes(t_vm *vm, int fd, unsigned int i);
void			u_big_endian_to_u(unsigned int *big_endian);
void			corewar_vm(int ac, char **av);
void			init(int ac, char **av, t_vm *vm);
void			complete_player_id(int ac, char **av, t_vm *vm);
void			exit_failure(t_vm *vm, char *error_message, char *file,
					t_bool call_perror);
void			dump(t_vm *vm);
void			print_player(t_vm *vm);
void			parsing(int ac, char **av, t_vm *vm);
void			count_player(int ac, char **av, t_vm *vm);
void			get_option_id(int ac, char **av, int *i, t_vm *vm);
void			get_cycle_to_dump(int ac, char **av, int *i, t_vm *vm);
void			set_option_id(char **av, int i, t_vm *vm);
void			load_champion_code(t_vm *vm, unsigned char *champion_code,
					int size);
void			print_winner(t_vm *vm);
void			game_loop(t_vm *vm);
void			check(t_vm *vm, t_cursor *cur, t_cursor *prev);
void			remove_cursor(t_vm *vm, t_cursor **cur, t_cursor **prev);
void			update_cursor(t_vm *vm, t_cursor *tmp);
t_bool			atol_overflow(const char *str, long long *result);
void			load_function(t_vm *vm);
void			load_cost(t_vm *vm);
void			get_ocp(t_vm *vm, unsigned long long pos, unsigned char *tab);
void			ft_live(t_vm *vm, t_cursor *cur);
void			ft_add(t_vm *vm, t_cursor *cur);
void			ft_sub(t_vm *vm, t_cursor *cur);
void			ft_and(t_vm *vm, t_cursor *cur);
void			ft_or(t_vm *vm, t_cursor *cur);
void			ft_xor(t_vm *vm, t_cursor *cur);
void			ft_fork(t_vm *vm, t_cursor *cur);
void			ft_lfork(t_vm *vm, t_cursor *cur);
unsigned int	get_mem(t_vm *vm, unsigned long long pc, long long pos,
					int size);
void			ft_ld(t_vm *vm, t_cursor *cur);
void			ft_lld(t_vm *vm, t_cursor *cur);
void			ft_ldi(t_vm *vm, t_cursor *cur);
void			ft_lldi(t_vm *vm, t_cursor *cur);
void			ft_zjmp(t_vm *vm, t_cursor *cur);
void			ft_aff(t_vm *vm, t_cursor *cur);
void			write_int(t_vm *vm, unsigned int value, unsigned long long pc,
					long long pos);
unsigned int	read_int(t_vm *vm, unsigned long long pc, long long pos);
void			ft_st(t_vm *vm, t_cursor *cur);
void			ft_sti(t_vm *vm, t_cursor *cur);
t_bool			is_reg(unsigned char reg);
t_bool			check_param(unsigned char *arg, int p0, int p1, int p2);
t_bool			check_one(unsigned char code, int allowed);
int				jump(unsigned char *arg, t_bool big_dir);
t_bool			check_reg(t_vm *vm, unsigned char type, unsigned long long pos);
unsigned int	arg_size(unsigned char arg, t_bool big_dir);
unsigned int	get_reg(t_vm *vm, t_cursor *cur, unsigned long long pos);
void			cpy_to_reg(unsigned int *reg, unsigned int value);
t_bool			check_3reg(t_vm *vm, t_cursor *cur, unsigned char *arg,
					t_bool big_dir);
unsigned int	lget_mem(t_vm *vm, unsigned long long pc,
					long long pos, int size);
unsigned int	lread_int(t_vm *vm, unsigned long long pc, long long pos);

t_window		*init_window(t_vm *vm, t_window *window);
int				init_visu(t_vm *vm);
void			display_round(t_vm *vm);
void			refresh_window(t_vm *vm);
void			aff_memory(t_vm *vm);
void			aff_info(t_vm *vm);
void			aff_champions(t_vm *vm);
void			display_round(t_vm *vm);
void			color_arena(t_vm *vm, t_cursor *cursor, unsigned long long pos);
int				get_visu_input(t_vm *vm, int ch);
void			reset_light(t_vm *vm);
void			pair_colors(t_vm *vm);
void			color_player(t_vm *vm, size_t act_player,
					size_t size, size_t nb_player);
#endif
