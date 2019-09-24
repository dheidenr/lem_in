/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 07:34:20 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/14 21:01:53 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_free(t_list **lst)
{
	t_list		*clr;

	while (lst)
	{
		clr = (*lst)->next;
		free(lst);
		*lst = clr;
	}
	(*lst) = NULL;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*tmp_list;
	t_list		*start;

	if (!lst || !f)
		return (NULL);
	tmp_list = ft_lstnew(NULL, 0);
	tmp_list = f(lst);
	if (tmp_list == NULL)
		return (NULL);
	start = tmp_list;
	while (lst->next)
	{
		lst = lst->next;
		tmp_list->next = f(lst);
		if (tmp_list->next == NULL)
		{
			ft_free(&start);
			return (NULL);
		}
		tmp_list = tmp_list->next;
	}
	return (start);
}
