/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:21:15 by ssfar             #+#    #+#             */
/*   Updated: 2019/11/10 16:59:04 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# define BUFF_SIZE 7

typedef struct	s_glist
{
	int				fd;
	char			*s;
	struct s_glist	*next;
}				t_glist;
int				get_next_line(const int fd, char **line);
int				gnl_no_buff(const int fd, char **line);
#endif
