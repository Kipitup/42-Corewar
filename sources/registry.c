/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   registry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 15:36:47 by ssfar             #+#    #+#             */
/*   Updated: 2020/05/08 15:36:47 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	i_to_reg(unsigned char *reg, int value, t_bool big_endian)
{
	int				i;
	int				j;
	unsigned char	*p;

	p = (unsigned char *)(&value);
	i = REG_SIZE - 1;
	if (big_endian == true)
	{
		j = 3;
		while (i > -1)
			reg[i--] = p[j--];
	}
	else
	{
		j = 0;
		while (i > -1)
			reg[i--] = p[j++];
	}
}

int	reg_to_i(unsigned char *reg, t_bool big_endian)
{
	int				i;
	int				j;
	unsigned char	*p;
	int				ret;

	ret = 0;
	p = (unsigned char *)(&ret);
	i = REG_SIZE - 1;
	if (big_endian == true)
	{
		j = 3;
		while (i > -1)
			p[j--] = reg[i--];
	}
	else
	{
		j = 0;
		while (i > -1)
			p[j++] = reg[i--];
	}
	return (ret);
}