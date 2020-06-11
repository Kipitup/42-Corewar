/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 16:55:23 by sadahan           #+#    #+#             */
/*   Updated: 2020/06/11 18:33:18 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*get_filename(char *str)
{
	char		*filename;
	int			length;

	length = ft_strlen(str);
	if (!(filename = ft_memalloc(sizeof(char) * (length + 3))))
		error_malloc(-1);
	filename = ft_strncpy(filename, str, length - 1);
	filename = ft_strcat(filename, "cor");
	return (filename);
}

int				main(int ac, char **av)
{
	char		*filename;

	usage_asm(ac, av);
	filename = get_filename(av[1]);
	if (!parse_file(av[1], filename))
	{
		ft_strdel(&filename);
		return (1);
	}
	ft_strdel(&filename);
	return (0);
}
