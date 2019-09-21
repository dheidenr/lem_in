/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exdlstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:06:45 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/21 13:06:48 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exdlst.h"
#include "libft.h"

void		init_points(t_exdlist *exdlist)
{
	exdlist->next = NULL;
	exdlist->prev = NULL;
	exdlist->start = exdlist;
	exdlist->end = exdlist;
}

t_exdlist	*exdlstnew(void const *content, size_t content_size)
{
	t_exdlist *exdlist;

	exdlist = ft_memalloc(sizeof(t_exdlist));
	if (!exdlist || content_size == 0)
		return (NULL);
	if (content == NULL)
	{
		exdlist->content = NULL;
		exdlist->content_size = 0;
		init_points(exdlist);
		return (exdlist);
	}
	if ((exdlist->content = ft_memalloc(content_size)))
	{
		ft_memcpy(exdlist->content, content, content_size);
		exdlist->content_size = content_size;
		init_points(exdlist);
		return (exdlist);
	}
	else
		free(exdlist->content);
	exdlist->content_size = content_size;
	return (NULL);
}
