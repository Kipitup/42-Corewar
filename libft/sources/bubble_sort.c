/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <samisfar.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:01:18 by ssfar             #+#    #+#             */
/*   Updated: 2020/07/23 02:09:41 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Sort numerically the (n) first elements of (arr) array.
*/

void	bubble_sort(size_t *arr, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
				u_swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}
