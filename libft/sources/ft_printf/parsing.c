/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 17:35:12 by ssfar             #+#    #+#             */
/*   Updated: 2019/12/11 13:09:29 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		read_format(char *format, t_flag *f, va_list arg)
{
	f->index = 0;
	f->len = 0;
	f->i = 0;
	while (format[f->i])
	{
		if (format[f->i] == '%')
		{
			buffer_str(f, format, f->i);
			format += f->i + 1;
			reset_flag(f);
			read_flag(&format, f, arg);
			get_variable(*format, f, arg);
			if (*format)
				format++;
		}
		else if (format[f->i] == '[')
			get_color(f, &format, arg);
		else
			f->i++;
	}
	if (f->i != 0)
		buffer_str(f, format, f->i);
	if (f->index)
		write(f->fd, f->buffer, f->index);
	return (f->len + f->index);
}

void	buffer_str(t_flag *f, char *str, int_fast32_t len)
{
	int_fast32_t	i;

	if (str)
	{
		i = 0;
		while (str[i] && i < len)
		{
			if (f->index == PRINTF_BUFF_SIZE)
			{
				write(f->fd, f->buffer, PRINTF_BUFF_SIZE);
				f->len += PRINTF_BUFF_SIZE;
				f->index = 0;
			}
			f->buffer[f->index++] = str[i++];
		}
	}
}

void	buffer_char(t_flag *f, int32_t c, int_fast32_t len)
{
	while (len > 0)
	{
		if (f->index == PRINTF_BUFF_SIZE)
		{
			write(f->fd, f->buffer, PRINTF_BUFF_SIZE);
			f->len += PRINTF_BUFF_SIZE;
			f->index = 0;
		}
		f->buffer[f->index++] = c;
		len--;
	}
}

void	get_variable(int_fast8_t type, t_flag *f, va_list arg)
{
	char	*str;
	ssize_t	nb;

	if (type == 'd' || type == 'i')
	{
		nb = get_va_int(arg, f->mod, f->z);
		str = itoa_no_symbol(nb);
		put_d(f, nb, str, ft_strlen(str));
	}
	else if (type == 's')
		put_s(f, va_arg(arg, char*));
	else if (type == 'f')
		put_f(f, arg);
	else if (type == '%')
		put_percent(f);
	else if (type == 'c')
		put_c(f, va_arg(arg, int32_t));
	else if (ischarset(type, "buoxX"))
		get_unsigned(type, f, get_va_uint(arg, f->mod, f->z));
	else if (type == 'p')
		put_p(f, get_va_uint(arg, 64, f->z));
}

void	get_unsigned(int_fast8_t type, t_flag *f, size_t unb)
{
	if (type == 'u')
		put_u(f, unb, utoa_base(unb, "0123456789"));
	else if (type == 'b')
		put_b(f, unb, utoa_base(unb, "01"));
	else if (type == 'o')
		put_o(f, unb, utoa_base(unb, "01234567"));
	else if (type == 'x')
		put_x(f, unb, utoa_base(unb, "0123456789abcdef"));
	else if (type == 'X')
		put_xx(f, unb, utoa_base(unb, "0123456789ABCDEF"));
}
