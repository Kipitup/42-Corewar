/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 16:04:49 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 19:29:38 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_flag(t_flag *f)
{
	f->i = 0;
	f->width = 0;
	f->precision = 0;
	f->minus = 0;
	f->plus = 0;
	f->sharp = 0;
	f->zero = 0;
	f->space = 0;
	f->dot = 0;
	f->mod = 32;
	f->l = 0;
	f->z = 0;
}

void	read_flag(char **format, t_flag *f, va_list arg)
{
	while (**format)
	{
		if ((**format >= '1' && **format <= '9') || **format == '*')
			get_width(format, arg, &f->width, &f->minus);
		else if (**format == '.')
			get_precision(format, arg, &f->precision, &f->dot);
		else if (**format == 'h' || **format == 'l' || **format == 'z')
			modifier(format, &f->mod, &f->z);
		else if (**format == 'L')
			f->l = 1;
		else if (**format == '-')
			f->minus = 1;
		else if (**format == '+')
			f->plus = 1;
		else if (**format == '#')
			f->sharp = 1;
		else if (**format == '0')
			f->zero = 1;
		else if (**format == ' ')
			f->space = 1;
		else
			break ;
		(*format)++;
	}
}

void	get_precision(char **format, va_list arg, int32_t *precision,
	uint_fast8_t *dot)
{
	int_fast32_t nb;

	*dot = 1;
	(*format)++;
	if (**format == '*')
	{
		nb = get_va_uint(arg, 32, 0);
		if (nb >= 0)
			*precision = nb;
		else
			*dot = 0;
	}
	else
	{
		while (**format && ft_isdigit(**format))
		{
			*precision = *precision * 10 + **format - '0';
			(*format)++;
		}
		(*format)--;
	}
}

void	get_width(char **format, va_list arg, int32_t *width,
	uint_fast8_t *minus)
{
	int_fast32_t nb;

	if (**format == '*')
	{
		nb = get_va_uint(arg, 32, 0);
		if (nb < 0)
		{
			*width = -nb;
			*minus = 1;
		}
		else
			*width = nb;
	}
	else
	{
		*width = 0;
		while (**format && ft_isdigit(**format))
		{
			*width = *width * 10 + **format - '0';
			(*format)++;
		}
		(*format)--;
	}
}

void	modifier(char **format, uint_fast8_t *mod, uint_fast8_t *z)
{
	if (**format == 'h')
	{
		if (*(*format + 1) == 'h')
		{
			*mod = 8;
			(*format)++;
		}
		else
			*mod = 16;
	}
	else if (**format == 'l')
	{
		*mod = 64;
		if (*(*format + 1) == 'l')
			(*format)++;
	}
	else
		*z = 1;
}
