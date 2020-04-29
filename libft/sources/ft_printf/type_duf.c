/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_duf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 16:07:28 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 19:34:04 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_d(t_flag *f, ssize_t nb, char *str, int_fast32_t len)
{
	if (nb < 0 || f->plus || f->space)
		f->width--;
	f->width -= len;
	if (f->precision > len)
		f->width -= f->precision - len;
	else if (nb == 0 && f->dot && f->precision == 0)
		f->width += len;
	if (!f->minus && (!f->zero || f->dot))
		buffer_char(f, ' ', f->width);
	if (nb < 0)
		buffer_char(f, '-', 1);
	else if (f->plus)
		buffer_char(f, '+', 1);
	else if (f->space)
		buffer_char(f, ' ', 1);
	if (f->zero && !f->minus && !f->dot)
		buffer_char(f, '0', f->width);
	if (f->precision > len)
		buffer_char(f, '0', f->precision - len);
	if (nb != 0 || !f->dot || f->precision != 0)
		buffer_str(f, str, len);
	if (f->minus)
		buffer_char(f, ' ', f->width);
	if (str)
		free(str);
}

void	put_u(t_flag *f, size_t unb, char *str)
{
	int_fast32_t len;

	len = ft_strlen(str);
	f->width -= len;
	if (f->precision > len)
		f->width -= f->precision - len;
	else if (unb == 0 && f->dot && f->precision == 0)
		f->width += len;
	if (!f->minus && (!f->zero || f->dot))
		buffer_char(f, ' ', f->width);
	else if (f->zero && !f->minus && !f->dot)
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

void	put_f(t_flag *f, va_list arg)
{
	char			*str;
	long double		fnb;

	if (!f->dot)
		f->precision = 6;
	fnb = (f->l ? va_arg(arg, long double) : va_arg(arg, double));
	str = aproximative_ftoa_no_symbol(fnb, f->precision, f->sharp);
	f->width -= ft_strlen(str);
	if (fnb < 0 || f->plus || f->space)
		f->width--;
	if (!f->minus && !f->zero)
		buffer_char(f, ' ', f->width);
	if (fnb < 0)
		buffer_char(f, '-', 1);
	else if (f->plus)
		buffer_char(f, '+', 1);
	else if (f->space)
		buffer_char(f, ' ', 1);
	if (f->zero && !f->minus)
		buffer_char(f, '0', f->width);
	buffer_str(f, str, ft_strlen(str));
	if (f->minus)
		buffer_char(f, ' ', f->width);
	if (str)
		free(str);
}
