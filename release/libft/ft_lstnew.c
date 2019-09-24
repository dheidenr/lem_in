/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 06:29:56 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/08 15:25:11 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	list = ft_memalloc(sizeof(t_list));
	if (!list || content_size == 18446744073709551615U)
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
		list->next = NULL;
		return (list);
	}
	list->content = ft_memalloc(content_size);
	if (list->content)
	{
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
		list->next = NULL;
		return (list);
	}
	else
		free(list->content);
	list->content_size = content_size;
	return (NULL);
}
