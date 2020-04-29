/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 16:16:14 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 19:30:08 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_flag			*f;
	va_list			arg;
	int_fast32_t	ret;

	if (!format || !(f = malloc(sizeof(t_flag))) || PRINTF_BUFF_SIZE < 1
	|| PRINTF_BUFF_SIZE > 255)
		return (0);
	va_start(arg, format);
	f->fd = 1;
	ret = read_format((char*)format, f, arg);
	va_end(arg);
	free(f);
	return (ret);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	t_flag			*f;
	va_list			arg;
	int_fast32_t	ret;

	if (!format || !(f = malloc(sizeof(t_flag))) || PRINTF_BUFF_SIZE < 1
	|| PRINTF_BUFF_SIZE > 255)
		return (0);
	va_start(arg, format);
	f->fd = fd;
	ret = read_format((char*)format, f, arg);
	va_end(arg);
	free(f);
	return (ret);
}
