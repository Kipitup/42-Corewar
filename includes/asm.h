/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 16:56:53 by sadahan           #+#    #+#             */
/*   Updated: 2020/06/11 18:38:28 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdlib.h>
# include "op.h"
# include "libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define LIL_END 0
# define BIG_END 1
# define BUFFER_SIZE 1000

/*
**	Error messages
*/

# define ERR_TYPE "Invalid syntax or agument type\n"
# define ERR_VALUE "Invalid syntax or argument value\n"
# define ERR_SEP "Too many arguments or separators\n"

/*
** used to check next char after instruction
*/

# define VALID_INST			" \t0123456789-%"
# define VALID_ARG			"r0123456789-:%"

/*
** Structure to store position in the file
** mainly for error management purpose
*/

typedef struct		s_pos
{
	int				line;
	int				col;
	int				i;
}					t_pos;

/*
** Structures to store instructions
*/

typedef struct		s_args
{
	int				val;
	int				type;
	char			*label;
	int				size;
}					t_args;

typedef struct		s_inst
{
	char			**label;
	int				opcode;
	int				nb_args;
	unsigned char	typecode;
	t_args			args[3];
	unsigned int	size;
	struct s_inst	*next;
}					t_inst;

/*
** Structure op_tab
** Files : op.c, check_instructs.c
** type_code :	0 = NO	1 = YES
** dir_size :	0 = 4	1 = T_DIR(2)
*/

typedef struct		s_op
{
	char			*name;
	int				nb_arg;
	int				arg[3];
	char			opcode;
	int				nb_cycle;
	char			*description;
	int				type_code;
	int				dir_size;
}					t_op;

t_op				*optab(void);

/*
** Dynamic strings structure (thanks to cbretagn)
*/

typedef struct		s_dstring
{
	unsigned int	size;
	unsigned int	capacity;
	char			*str;
}					t_dstring;

/*
** Parsing functions
** File : parser_asm.c
*/

int					parse_file(char *str, char *name);

/*
** Check and fill header as in op.h with champion name
** and comment, magic number and instructs size
** Files : header_asm.c check_header.c
*/

t_pos				*fill_header(t_pos *p, t_header *header, char *file);
int					fill_name_comment(char *file, t_pos *p,
					t_header *header, char *cmd);
void				fill_prog_size(t_header *header, t_inst **instructs);

int					check_endline(char *file, t_pos *p);
int					check_command(char *file, t_pos *p, t_header *header);
int					check_name_comment(char *file, t_pos *p, t_header *header,
					char *cmd);

/*
** Check and fill instructions structure
** Files : instructs_asm.c check_instructs.c get_instructs.c
*/

t_inst				*fill_instructs(t_pos *p, t_inst *instructs, char *file);

t_op				check_valid_inst(char *inst);
t_inst				*check_valid_args(char *args, t_op op, t_inst *new,
					t_pos *p);

t_inst				*get_inst_args(char *file, t_pos *p, t_inst *new, t_op op);
void				fill_typecode_and_size(t_op op, t_inst *new);
t_inst				**replace_labels(t_inst **instructs, t_pos *p, char *file);
unsigned int		instructs_size(t_inst **instructs);

/*
** Error management
** File : errors_asm.c
*/

void				usage_asm(int ac, char **av);
void				error_malloc(int error);
void				*error_asm(char *error, int line, int col);
int					check_filename_asm(char *file);
void				*error_label(char *label, t_pos *p, char *file);

/*
** Utility functions
** File : util_asm.c line_asm.c
*/

int					endian(void);
unsigned int		reverse_bytes(unsigned int n);
int					is_blank(char c);
int					skip_blank_or_comment(char *file, t_pos *p);
t_pos				*init_pos(t_pos *p);
void				update_pos(t_pos *p, char c);

/*
** Instructs list functions
** File : struct_asm.c
*/

void				add_to_list(t_inst **list, t_inst *new);
t_inst				*delete_struct(t_inst **list);
t_inst				*delete_elem(t_inst *elem);

/*
** Free functions
** File : delete_asm.c
*/

int					free_return(t_dstring *file, t_header *header, t_pos *p,
					int ret);
int					del_str(char *str, int nb);

/*
** Dynamic strings functions (thanks to cbretagn)
*/

t_dstring			*create_dstring(unsigned int cap, char *str);
t_dstring			*push_str(t_dstring *dest, char *src);
t_dstring			*delete_dstring(t_dstring *del);

#endif
