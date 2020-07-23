/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <samisfar.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 16:16:14 by ssfar             #+#    #+#             */
/*   Updated: 2020/07/24 01:44:15 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Output to stdout according to a format.
** Read man 3 printf for more info.
** Few option not inplemented, read 42 ft_printf subject for more info.
** Bonus :
** - %b to print in binary.
** - [r;g;b] replace rgb by values between 0 to 255 to modify text color.
** - [r;*;b] use wildcard to give the value via a variable.
** - [attribute] replace attribute by one of the folowed options
** (a_reset, a_eoc, a_eob, a_bold, a_faint, a_italic, a_underlined, a_blink,
** a_reverse, a_hidden).
** or one of those colors to modify followed text color (black, red, green,
** yellow, blue, magenta, cyan, white).
** add b_ in front of the color to modify the background color.
*/

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

/*
** Same as ft_printf() function but output to the given file descriptor (fd).
*/

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
