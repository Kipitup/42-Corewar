/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_asm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 16:53:40 by sadahan           #+#    #+#             */
/*   Updated: 2020/06/09 18:50:01 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
** Cleaning functions
*/

int		free_return(t_dstring *file, t_header *header, t_pos *p, int ret)
{
	delete_dstring(file);
	free(header);
	free(p);
	return (ret);
}

int		del_str(char *str, int nb)
{
	ft_strdel(&str);
	return (nb);
}
