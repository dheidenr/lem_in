/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:54:05 by dheidenr          #+#    #+#             */
/*   Updated: 2019/06/20 13:54:10 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	dlistlen(t_dlist *stack)
{
	size_t	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_dlist	*dlstdub(t_dlist *stack)
{
	t_dlist	*temp;
	t_dlist	*dlist;

	dlist = stack;
	if (!stack)
		return (NULL);
	while (dlist->next)
		dlist = dlist->next;
	temp = NULL;
	while (dlist)
	{
		if (!dlist->next)
			temp = ft_dlstnew((int *)dlist->content,
					sizeof(*(int *)dlist->content));
		else
			ft_dlstadd(&temp, ft_dlstnew((int *)dlist->content,
					sizeof(*(int *)dlist->content)));
		dlist = dlist->prev;
	}
	return (temp);
}
