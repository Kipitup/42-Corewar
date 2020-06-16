/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 16:56:53 by sadahan           #+#    #+#             */
/*   Updated: 2020/06/16 14:36:44 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVASM_H
# define REVASM_H

# include "asm.h"

/*
** Structures to store instructions
*/

typedef struct			s_revargs
{
	int					val;
	int					type;
	int					size;
}						t_revargs;

typedef struct			s_revinst
{
	char				*name;
	int					nb_args;
	unsigned char		typecode;
	t_revargs			args[3];
	int					size;
	struct s_revinst	*next;
}						t_revinst;

void					usage_revasm(int ac, char **av);
void					*error_read(t_header *header, char *s);
void					*error_del(char *s);

char					*read_file(char *str, t_header *header);
void					write_file(char *name, t_revinst **instructs,
						t_header *header);

t_op					get_name(int op);

t_revinst				*delete_r_struct(t_revinst **list);
void					add_to_rlist(t_revinst **list, t_revinst *new);

t_revinst				*parse_instructs(t_revinst *instructs, char *code);

#endif
