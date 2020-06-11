/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_revasm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 17:49:50 by user42            #+#    #+#             */
/*   Updated: 2020/06/11 18:33:22 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "revasm.h"

static char		*get_filename(char *str)
{
	char		*filename;
	int			length;

	length = ft_strlen(str);
	if (!(filename = ft_memalloc(sizeof(char) * (length - 1))))
		error_malloc(-1);
	filename = ft_strncpy(filename, str, length - 3);
	filename = ft_strcat(filename, "s");
	return (filename);
}

static void		clean_main(t_revinst *instructs, t_header *header,
				char *code, char *filename)
{
	delete_r_struct(&instructs);
	free(header);
	ft_strdel(&code);
	ft_strdel(&filename);
}

int				main(int ac, char **av)
{
	char		*filename;
	char		*code;
	t_header	*header;
	t_revinst	*instructs;

	usage_revasm(ac, av);
	filename = get_filename(av[1]);
	instructs = NULL;
	code = NULL;
	if (!(header = ft_memalloc(sizeof(t_header))))
		error_malloc(-1);
	if (!(code = read_file(av[1], header)))
	{
		error_read(header, filename);
		return (1);
	}
	instructs = parse_instructs(instructs, code);
	write_file(filename, &instructs, header);
	write(1, "Writing output program to ", 26);
	write(1, filename, ft_strlen(filename));
	write(1, "\n", 1);
	clean_main(instructs, header, code, filename);
	return (0);
}
