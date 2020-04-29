/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:55:00 by ssfar             #+#    #+#             */
/*   Updated: 2019/08/15 17:58:17 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Create and return a new link.
** The element list->next is initialised to NULL, list->content_size and
** list->content are initialised whit (content_size) and (content).
** If (content) is NULL, list->content_size is initialised whit 0 regardless
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
