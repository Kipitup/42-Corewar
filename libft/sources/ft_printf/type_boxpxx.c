/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_boxpxx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 15:41:03 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 19:33:32 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_b(t_flag *f, size_t unb, char *str)
{
	int_fast32_t len;

	len = ft_strlen(str);
	if (f->sharp && unb != 0)
		f->width -= 2;
	f->width -= len;
	if (f->precision > len)
		f->width -= f->precision - len;
	else if (unb == 0 && f->dot && f->precision == 0)
		f->width += len;
	if (!f->minus && (!f->zero || f->dot))
		buffer_char(f, ' ', f->width);
	if (f->sharp && unb != 0)
		buffer_str(f, "0b", 2);
	if (f->zero && !f->dot && !f->minus)
		buffer_char(f, '0', f->width);
	if (f->precision > len)
		buffer_char(f, '0', f->precision - len);
	if (unb != 0 || !f->dot || f->precision != 0)
		buffer_str(f, str, len);
	if (f->minus)
		buffer_char(f, ' ', f->width);
	if (str)
		free(str);
}

void	put_o(t_flag *f, size_t unb, char *str)
{
	int_fast32_t len;

	len = ft_strlen(str);
	if (f->sharp && unb != 0)
		len++;
	f->width -= len;
	if (f->precision > len)
		f->width -= f->precision - len;
	else if (unb == 0 && f->dot && f->precision == 0 && !f->sharp)
		f->width += len;
	if (!f->minus && (!f->zero || f->dot))
		buffer_char(f, ' ', f->width);
	if (unb > 0 && f->sharp)
		buffer_char(f, '0', 1);
	if (f->zero && !f->minus && !f->dot)
		buffer_char(f, '0', f->width);
	if (f->precision > len)
		buffer_char(f, '0', f->precision - len);
	if (unb != 0 || !f->dot || f->precision != 0 || f->sharp)
		buffer_str(f, str, len);
	if (f->minus)
		buffer_char(f, ' ', f->width);
	if (str)
		free(str);
}

void	put_x(t_flag *f, size_t unb, char *str)
{
	int_fast32_t len;

	len = ft_strlen(str);
	if (f->sharp && unb != 0)
		f->width -= 2;
	f->width -= len;
	if (f->precision > len)
		f->width -= f->precision - len;
	else if (unb == 0 && f->dot && f->precision == 0)
		f->width += len;
	if (!f->minus && (!f->zero || f->dot))
		buffer_char(f, ' ', f->width);
	if (f->sharp && unb != 0)
		buffer_str(f, "0x", 2);
	if (f->zero && !f->dot && !f->minus)
		buffer_char(f, '0', f->width);
	if (f->precision > len)
		buffer_char(f, '0', f->precision - len);
	if (unb != 0 || !f->dot || f->precision != 0)
		buffer_str(f, str, len);
	if (f->minus)
		buffer_char(f, ' ', f->width);
	if (str)
		free(str);
}

void	put_xx(t_flag *f, size_t unb, char *str)
{
	int_fast32_t len;

	len = ft_strlen(str);
	if (f->sharp && unb > 0)
		f->width -= 2;
	f->width -= len;
	if (f->precision > len)
		f->width -= f->precision - len;
	else if (unb == 0 && f->dot && f->precision == 0)
		f->width += len;
	if (!f->minus && (!f->zero || f->dot))
		buffer_char(f, ' ', f->width);
	if (f->sharp && unb != 0)
		buffer_str(f, "0X", 2);
	if (f->zero && !f->dot && !f->minus)
		buffer_char(f, '0', f->width);
	if (f->precision > len)
		buffer_char(f, '0', f->precision - len);
	if (unb != 0 || !f->dot || f->precision != 0)
		buffer_str(f, str, len);
	if (f->minus)
		buffer_char(f, ' ', f->width);
	if (str)
		free(str);
}

void	put_p(t_flag *f, size_t unb)
{
	char			*str;
	int_fast32_t	len;

	str = utoa_base(unb, "0123456789abcdef");
	len = ft_strlen(str);
	f->width -= len + 2;
	if (f->precision > len)
		f->width -= f->precision - len;
	else if (unb == 0 && f->dot && f->precision == 0)
		f->width += len;
	if (!f->minus && (!f->zero || f->dot))
		buffer_char(f, ' ', f->width);
	buffer_str(f, "0x", 2);
	if (f->zero && !f->minus && !f->dot)
		buffer_char(f, '0', f->width);
	if (f->precision > len)
		buffer_char(f, '0', f->precision - len);
	if (unb != 0 || !f->dot || f->precision != 0)
		buffer_str(f, str, len);
	if (f->minus)
		buffer_char(f, ' ', f->width);
	if (str)
		free(str);
}
