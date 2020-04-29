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
	unsigned int	nb_player;
	unsigned int	*player_id;
	unsigned int	cycle_counter;
	unsigned int	live_counter;
	unsigned int	dump;
	t_bool			visualiser;
}					t_vm;

/*
**
*/

#endif
