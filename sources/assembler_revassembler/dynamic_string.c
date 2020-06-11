/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:03:21 by cbretagn          #+#    #+#             */
/*   Updated: 2020/06/11 18:32:14 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_dstring			*create_dstring(unsigned int cap, char *str)
{
	t_dstring		*ret;
	unsigned int	len;

	if (!(ret = (t_dstring *)malloc(sizeof(t_dstring))))
		error_malloc(-1);
	len = ft_strlen(str);
	ret->capacity = cap;
	ret->size = len;
	if (!(ret->str = ft_strnew(ret->capacity)))
		error_malloc(-1);
	if (str[0] != '\0')
		ft_strcpy(ret->str, str);
	return (ret);
}

t_dstring			*delete_dstring(t_dstring *del)
{
	ft_strdel(&del->str);
	free(del);
	del = NULL;
	return (NULL);
}

t_dstring			*push_str(t_dstring *dest, char *src)
{
	t_dstring		*temp;
	int				new_cap;
	unsigned int	len;

	len = ft_strlen(src);
	temp = dest;
	if (len < temp->capacity - temp->size)
		ft_strcpy((temp->str + temp->size), src);
	else
	{
		temp = NULL;
		new_cap = dest->capacity;
		while (len >= new_cap - dest->size)
			new_cap *= 2;
		if (!(temp = create_dstring(new_cap, dest->str)))
			return (NULL);
		delete_dstring(dest);
		ft_strcpy((temp->str + temp->size), src);
	}
	temp->size += len;
	return (temp);
}
