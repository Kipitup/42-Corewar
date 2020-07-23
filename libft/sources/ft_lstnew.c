/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <samisfar.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:55:00 by ssfar             #+#    #+#             */
/*   Updated: 2020/07/24 01:40:37 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Create and return a new link.
** The element list->next is initialised to NULL, list->content_size and
** list->content are initialised with (content_size) and (content).
** If (content) is NULL, list->content_size is initialised with 0 regardless
** of the parameter (content_size).
** <i> the output link is malloced.
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	list->content = NULL;
	list->content_size = 0;
	if (content)
	{
		if (!(list->content = malloc(sizeof(*(list->content)) * content_size)))
		{
			free(list);
			return (NULL);
		}
		list->content = ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
