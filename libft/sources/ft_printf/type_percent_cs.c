/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent_cs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 16:03:08 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 19:34:31 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_percent(t_flag *f)
{
	f->width--;
	if (!f->minus && !f->zero)
		buffer_char(f, ' ', f->width);
	else if (f->zero && !f->minus)
		buffer_char(f, '0', f->width);
	buffer_char(f, '%', 1);
	if (f->minus)
		buffer_char(f, ' ', f->width);
}

void	put_c(t_flag *f, int32_t c)
{
	f->width--;
	if (!f->minus && !f->zero)
		buffer_char(f, ' ', f->width);
	else if (f->zero && !f->minus)
		buffer_char(f, '0', f->width);
	buffer_char(f, c, 1);
	if (f->minus)
		buffer_char(f, ' ', f->width);
}

void	put_s(t_flag *f, char *str)
{
	int_fast32_t	len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (f->dot && f->precision < len)
		len = f->precision;
	f->width -= len;
	if (!f->minus && !f->zero)
		buffer_char(f, ' ', f->width);
	else if (f->zero && !f->minus)
		buffer_char(f, '0', f->width);
	buffer_str(f, str, len);
	if (f->minus)
		buffer_char(f, ' ', f->width);
}
