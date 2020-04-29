/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 16:13:04 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/19 19:33:10 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint_fast8_t	check_rgb(char *color)
{
	uint_fast8_t	i;
	uint_fast8_t	j;
	size_t			rgb[3];

	i = 0;
	j = 0;
	while (color[i] && j < 3)
	{
		if (color[i] >= '0' && color[i] <= '9')
			rgb[j++] = ft_atoi(&color[i]);
		else
			return (0);
		while (color[i] >= '0' && color[i] <= '9')
			i++;
		if (color[i] == ';')
			i++;
		else
			break ;
	}
	if (color[i] != '\0' || rgb[0] > 255 || rgb[1] > 255 || rgb[2] > 255)
		return (0);
	return (1);
}

void			get_rgb(char **format, t_flag *f, char *color)
{
	char			*str;
	uint_fast8_t	background;

	background = 0;
	if (color[0] == 'b')
	{
		color++;
		background = 1;
	}
	str = background ? ft_strjoin(B_RGB, color) : ft_strjoin(RGB, color);
	str = strjoin_free(str, "m", 1);
	put_color(str, format, f, ft_strlen(color) + background);
	if (str)
		free(str);
}

void			get_rgb_wildcard(char **format, t_flag *f, va_list arg,
	char *color)
{
	char	*str;

	str = strjoin_free(ft_itoa(get_va_uint(arg, 8, 0)), ";", 1);
	str = strjoin_free(str, ft_itoa(get_va_uint(arg, 8, 0)), 2);
	str = strjoin_free(str, ";", 1);
	str = strjoin_free(str, ft_itoa(get_va_uint(arg, 8, 0)), 2);
	str = strjoin_free(str, "m", 1);
	if (color[0] == 'b')
		str = strjoin_free(B_RGB, str, 2);
	else
		str = strjoin_free(RGB, str, 2);
	put_color(str, format, f, ft_strlen(color));
	if (str)
		free(str);
}
