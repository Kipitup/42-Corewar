/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_revasm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 19:44:03 by sadahan           #+#    #+#             */
/*   Updated: 2020/06/18 16:23:44 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "revasm.h"

static void			get_size(t_revinst *new, t_op op)
{
	int				n;

	n = 0;
	while (n < new->nb_args)
	{
		if (new->args[n].type == T_IND)
			new->args[n].size = IND_SIZE;
		else if (new->args[n].type == T_DIR)
			new->args[n].size = (op.dir_size) ? T_DIR : 4;
		else
			new->args[n].size = 1;
		n++;
	}
}

static void			get_type(t_revinst *new, t_op op)
{
	int				n;
	int				i;

	n = 0;
	i = 6;
	if (!new->typecode)
		new->args[n].type = T_DIR;
	else
		while (n < new->nb_args)
		{
			if (((new->typecode >> i) & IND_CODE) == 3)
				new->args[n].type = T_IND;
			else if (((new->typecode >> i) & DIR_CODE) == 2)
				new->args[n].type = T_DIR;
			else if (((new->typecode >> i) & REG_CODE) == 1)
				new->args[n].type = T_REG;
			n++;
			i -= 2;
		}
	get_size(new, op);
}

static int			get_value(char *code, t_revinst *new, int n)
{
	size_t			i;
	unsigned int	nb;

	nb = 0;
	i = 0;
	while (i < (size_t)new->args[n].size)
	{
		nb <<= 8;
		nb += (unsigned char)code[i];
		i++;
	}
	if (i < 4)
		new->args[n].val = (short)nb;
	else
		new->args[n].val = (int)nb;
	return (new->args[n].size);
}

static t_revinst	*new_inst(char *code)
{
	t_revinst		*new;
	int				n;
	int				i;
	t_op			op;

	i = 1;
	if (!(new = ft_memalloc(sizeof(t_revinst))))
		error_malloc(-1);
	n = (int)code[0];
	op = get_name(n);
	if (!(new->name = ft_memalloc(sizeof(char) * ft_strlen(op.name) + 1)))
		error_malloc(-1);
	new->name = ft_strcpy(new->name, op.name);
	new->nb_args = op.nb_arg;
	if (op.type_code == 1)
		new->typecode = code[i++];
	get_type(new, op);
	n = 0;
	while (n < new->nb_args)
	{
		i += get_value(&code[i], new, n);
		n++;
	}
	new->size = i;
	return (new);
}

t_revinst			*parse_instructs(t_revinst *instructs, char *code)
{
	t_revinst		*new;
	int				i;

	i = 0;
	while (code[i])
	{
		new = new_inst(&code[i]);
		i += new->size;
		add_to_rlist(&instructs, new);
	}
	return (instructs);
}
