/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructs_asm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 16:54:54 by sadahan           #+#    #+#             */
/*   Updated: 2020/06/11 18:32:41 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Check and fill instructions structure
** t_inst definition can be find in file asm.h
** Files : op.c instructs_asm.c check_valid_instructs.c
*/

static int		check_labels(char *file, t_pos *p, t_dstring *labels)
{
	char		*tmp;
	int			start;

	start = p->i;
	if (!file[p->i])
		return (0);
	while (file[p->i] && ft_strchr(LABEL_CHARS, file[p->i]))
		p->i++;
	if (file[p->i] == LABEL_CHAR)
	{
		if (!(tmp = ft_strsub(file, start, p->i - start + 1)))
			error_malloc(-1);
		if (!(labels = push_str(labels, tmp)))
			error_malloc(-1);
		p->col += ft_strlen(tmp);
		ft_strdel(&tmp);
		return (1);
	}
	p->i = start;
	return (0);
}

static t_inst	*check_instruct(char *file, t_pos *p, t_inst *new)
{
	char		*tmp;
	int			start;
	t_op		op;

	start = p->i;
	if (!file[p->i])
		return (new);
	while (file[p->i] && ft_isalpha(file[p->i]))
		update_pos(p, file[p->i++]);
	if (!(tmp = ft_strsub(file, start, p->i - start)))
		error_malloc(-1);
	op = check_valid_inst(tmp);
	ft_strdel(&tmp);
	if (!file[p->i] || !ft_strchr(VALID_INST, file[p->i]) || !op.name)
		return (error_asm("Invalid instruction\n", p->line, p->col));
	new->opcode = op.opcode;
	if (!get_inst_args(file, p, new, op))
		return (NULL);
	return (new);
}

static t_inst	*read_instruct_line(char *file, t_pos *p)
{
	t_inst		*new;
	t_dstring	*labels;
	int			endline;

	endline = 0;
	if (!(new = ft_memalloc(sizeof(t_inst))))
		error_malloc(-1);
	if (!(labels = create_dstring(1000, "")))
		error_malloc(-1);
	while (check_labels(file, p, labels))
		endline = skip_blank_or_comment(file, p);
	if (!(new->label = ft_strsplit(labels->str, ':')))
		error_malloc(-1);
	delete_dstring(labels);
	if (!file[p->i] && endline == 0)
	{
		ft_free_tab(new->label);
		free(new);
		return (error_asm("Missing instruction or endline\n", p->line, p->col));
	}
	if (!(check_instruct(file, p, new)))
		return (delete_elem(new));
	return (new);
}

t_inst			*fill_instructs(t_pos *p, t_inst *instructs, char *file)
{
	t_inst		*new;

	while (file)
	{
		skip_blank_or_comment(file, p);
		if (!file[p->i])
		{
			if (!instructs)
				return (error_asm("File must contain at least one "
					"instruction\n", p->line, p->col));
				break ;
		}
		if (!(new = read_instruct_line(file, p)))
			return (delete_struct(&instructs));
		add_to_list(&instructs, new);
		if (!check_endline(file, p))
		{
			error_asm("Missing newline after "
				"instruction\n", p->line, p->col - 1);
			return (delete_struct(&instructs));
		}
	}
	if (!replace_labels(&instructs, p, file))
		return (delete_struct(&instructs));
	return (instructs);
}
