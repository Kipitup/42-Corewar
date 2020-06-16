/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_revasm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 17:49:43 by user42            #+#    #+#             */
/*   Updated: 2020/06/16 14:36:25 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "revasm.h"

static int	check_filename(char *file)
{
	if (!file)
		return (0);
	if (ft_strncmp(&file[ft_strlen(file) - 4], ".cor", 4) != 0)
		return (0);
	return (1);
}

void		usage_revasm(int ac, char **av)
{
	if (ac != 2 || !(check_filename(av[1])))
	{
		write(2, "Usage : ./revasm [file_name.cor]\n", 33);
		exit(-1);
	}
}

void		*error_read(t_header *header, char *s)
{
	write(2, "Can't read source file\n", 23);
	if (header)
		free(header);
	if (s)
		ft_strdel(&s);
	return (NULL);
}

void		*error_del(char *s)
{
	if (s)
		ft_strdel(&s);
	return (NULL);
}
