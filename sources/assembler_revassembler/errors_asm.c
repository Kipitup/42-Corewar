/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_asm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 16:54:11 by sadahan           #+#    #+#             */
/*   Updated: 2020/06/11 18:32:17 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Error messages return line and column in the file
*/

void		usage_asm(int ac, char **av)
{
	if (ac != 2 || !(check_filename_asm(av[1])))
	{
		write(2, "Usage : ./asm [file_name.s]\n", 28);
		exit(-1);
	}
}

int			check_filename_asm(char *file)
{
	if (!file)
		return (0);
	if (file[ft_strlen(file) - 1] != 's'
		|| file[ft_strlen(file) - 2] != '.')
		return (0);
	return (1);
}

void		error_malloc(int error)
{
	if (error == -1)
		write(2, "Malloc error, end of program\n", 29);
	if (error == -2)
		write(2, "Can't read source file\n", 23);
	if (error == -3)
		write(2, "Can't open destination file\n", 23);
	exit(-1);
}

void		*error_asm(char *error, int line, int col)
{
	write(2, "Error (line ", 12);
	ft_putnbr_fd(line, 2);
	write(2, ", col ", 6);
	ft_putnbr_fd(col, 2);
	write(2, ") : ", 4);
	write(2, error, ft_strlen(error));
	return (NULL);
}

void		*error_label(char *label, t_pos *p, char *file)
{
	size_t	i;
	size_t	j;

	i = 0;
	p->col = 0;
	p->line = 1;
	while (file[i++])
	{
		update_pos(p, file[i]);
		if (file[i] == LABEL_CHAR)
		{
			j = i + 1;
			while (ft_strchr(LABEL_CHARS, file[j]))
				j++;
			if (ft_strlen(label) == (j - i - 1)
				&& !(ft_strncmp(&file[i + 1], label, j - i - 1)))
				return (error_asm("Unknown label used as argument\n",
					p->line + 1, p->col));
			else
				i++;
		}
	}
	return (NULL);
}
