/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 16:53:20 by sadahan           #+#    #+#             */
/*   Updated: 2020/06/11 18:32:06 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Checks if instructions are valid
** to fill struct in file "instructs_asm.c"
** Associated file : get_instructs.c
*/

t_op			check_valid_inst(char *inst)
{
	int			i;

	i = 0;
	while (optab()[i].name)
	{
		if (ft_strcmp(optab()[i].name, inst) == 0)
			return (optab()[i]);
		i++;
	}
	return (optab()[i]);
}

static t_inst	*check_arg_type(char c, t_op op, t_inst *new)
{
	int			n;

	n = new->nb_args;
	if (c == 'r')
	{
		new->args[n].type = T_REG;
		new->args[n].size = 1;
	}
	else if (c == DIRECT_CHAR)
	{
		new->args[n].type = T_DIR;
		new->args[n].size = (op.dir_size) ? T_DIR : 4;
	}
	else if (c == '-' || ft_isdigit(c) || c == LABEL_CHAR)
	{
		new->args[n].type = T_IND;
		new->args[n].size = IND_SIZE;
	}
	else
		return (NULL);
	if ((new->args[n].type & op.arg[n]) == 0)
		return (NULL);
	return (new);
}

static t_inst	*check_arg_value(char *arg, t_inst *nw)
{
	int			j;
	int			n;
	int			start;

	n = nw->nb_args;
	j = (nw->args[n].type == T_IND) ? 0 : 1;
	start = j + 1;
	if (arg[j] && (ft_isdigit(arg[j]) || arg[j] == '-'))
		nw->args[n].val = ft_atoi(&arg[j]);
	else if (nw->args[n].type != T_REG)
	{
		if (arg[j++] != LABEL_CHAR)
			return (NULL);
		while (arg[j] && ft_strchr(LABEL_CHARS, arg[j]))
			j++;
		if (!(nw->args[n].label = ft_strsub(arg, start, j - start)))
			error_malloc(-1);
	}
	if (nw->args[n].type == 1 && (!ft_isdigit(arg[j]) || nw->args[n].val > 99))
		return (NULL);
	while (ft_isdigit(arg[j]) || arg[j] == '-')
		j++;
	if (arg[j] && !is_blank(arg[j]) && arg[j] != SEPARATOR_CHAR)
		return (NULL);
	return (nw);
}

t_inst			*check_valid_args(char *args, t_op op, t_inst *new, t_pos *p)
{
	int			j;

	j = 0;
	while (args[j])
	{
		while (args[j] && is_blank(args[j]))
			update_pos(p, args[j++]);
		if (!(check_arg_type(args[j], op, new)))
			return (error_asm(ERR_TYPE, p->line, p->col));
		if (!(check_arg_value(&args[j], new)))
			return (error_asm(ERR_VALUE, p->line, p->col));
		new->nb_args++;
		while (args[j] && !is_blank(args[j]) && args[j] != SEPARATOR_CHAR)
			update_pos(p, args[j++]);
		while (args[j] && is_blank(args[j]))
			update_pos(p, args[j++]);
		if (args[j] && args[j] != SEPARATOR_CHAR)
			return (error_asm("Missing separator\n", p->line, p->col));
		if (args[j] && args[j++] == SEPARATOR_CHAR && new->nb_args >= op.nb_arg)
			return (error_asm(ERR_SEP, p->line, p->col));
	}
	if (new->nb_args != op.nb_arg)
		return (error_asm("Wrong number of arguments\n", p->line, p->col));
	return (new);
}
