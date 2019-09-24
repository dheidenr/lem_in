/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   future_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:54:45 by dheidenr          #+#    #+#             */
/*   Updated: 2019/06/20 13:54:48 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist *dlist;

	dlist = ft_memalloc(sizeof(t_dlist));
	if (!dlist || content_size == 18446744073709551615U)
		return (NULL);
	if (content == NULL)
	{
		dlist->content = NULL;
		dlist->content_size = 0;
		dlist->next = NULL;
		dlist->prev = NULL;
		return (dlist);
	}
	if ((dlist->content = ft_memalloc(content_size)))
	{
		ft_memcpy(dlist->content, content, content_size);
		dlist->content_size = content_size;
		dlist->next = NULL;
		dlist->prev = NULL;
		return (dlist);
	}
	else
		free(dlist->content);
	dlist->content_size = content_size;
	return (NULL);
}

void	ft_dlstdel(t_dlist **adlst, void (*del)(void *, size_t))
{
	t_dlist *next_lst;

	if (*adlst == NULL || !adlst || !del)
		return ;
	while (*adlst)
	{
		next_lst = (*adlst)->next;
		del((*adlst)->content, (*adlst)->content_size);
		free((*adlst));
		*adlst = NULL;
		*adlst = next_lst;
	}
	*adlst = NULL;
}

void	memsetdel(void *entity, size_t size)
{
	ft_memset(entity, 0, size);
	free(entity);
}

void	ft_dlstadd(t_dlist **adlst, t_dlist *new)
{
	if (adlst == NULL || new == NULL)
		return ;
	new->next = *adlst;
	(*adlst)->prev = new;
	*adlst = new;
}

t_dlist	*len_int_to_dlst(int *array)
{
	t_dlist	*dlist;
	int		len;

	len = array[0];
	dlist = ft_dlstnew(&array[len], sizeof(array[len]));
	len--;
	while (len)
	{
		ft_dlstadd(&dlist, ft_dlstnew(&array[len], sizeof(array[len])));
		len--;
	}
	return (dlist);
}
