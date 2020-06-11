/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 16:54:25 by sadahan           #+#    #+#             */
/*   Updated: 2020/06/11 18:32:31 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Checks if instructions are well formated
** to fill struct in file "instructs_asm.c"
** Associated file : check_instructs.c
*/

unsigned int		instructs_size(t_inst **instructs)
{
	unsigned int	size;
	t_inst			*curr;

	curr = *instructs;
	size = 0;
	while (curr)
	{
		size += curr->size;
		curr = curr->next;
	}
	return (size);
}

t_inst				*get_inst_args(char *file, t_pos *p, t_inst *new, t_op op)
{
	int				start;
	char			*args;
	char			*tmp;

	while (file[p->i] && (file[p->i] == ' ' || file[p->i] == '\t'))
		update_pos(p, file[p->i++]);
	start = p->i;
	while (file[p->i] && file[p->i] != ALT_COMMENT_CHAR
		&& file[p->i] != COMMENT_CHAR && file[p->i] != '\n')
		p->i++;
	if (!(tmp = ft_strsub(file, start, p->i - start)))
		error_malloc(-1);
	if (!(args = ft_strtrim(tmp)))
		error_malloc(-1);
	ft_strdel(&tmp);
	if (!check_valid_args(args, op, new, p))
	{
		ft_strdel(&args);
		return (NULL);
	}
	fill_typecode_and_size(op, new);
	p->i--;
	ft_strdel(&args);
	return (new);
}

void				fill_typecode_and_size(t_op op, t_inst *new)
{
	int				i;
	char			type;

	type = 0;
	i = -1;
	new->size = 1 + op.type_code;
	new->typecode = 0;
	if (op.type_code == 1)
	{
		while (++i < new->nb_args)
		{
			type = (new->args[i].type == T_IND) ? 3 : new->args[i].type;
			if (i == 0)
				new->typecode |= (type << 6);
			if (i == 1)
				new->typecode |= (type << 4);
			if (i == 2)
				new->typecode |= (type << 2);
		}
	}
	i = -1;
	while (++i < new->nb_args)
		new->size += new->args[i].size;
}

static int			find_label(char *label, t_inst **instructs)
{
	t_inst			*curr;
	int				i;
	int				curr_pos;

	curr_pos = 0;
	curr = *instructs;
	while (curr)
	{
		if (curr->label)
		{
			i = -1;
			while (curr->label[++i])
			{
				if (ft_strcmp(label, curr->label[i]) == 0)
					return (curr_pos);
			}
		}
		curr_pos += curr->size;
		curr = curr->next;
	}
	if (!curr)
		return (-1);
	return (curr_pos);
}

t_inst				**replace_labels(t_inst **instrs, t_pos *p, char *file)
{
	t_inst			*curr;
	int				i;
	int				curr_pos;
	int				label_pos;

	curr_pos = 0;
	label_pos = 0;
	curr = *instrs;
	while (curr)
	{
		i = -1;
		while (++i < curr->nb_args)
		{
			if (curr->args[i].label)
			{
				if ((label_pos = find_label(curr->args[i].label, instrs)) < 0)
					return (error_label(curr->args[i].label, p, file));
				curr->args[i].val = label_pos - curr_pos;
			}
		}
		curr_pos += curr->size;
		curr = curr->next;
	}
	return (instrs);
}
