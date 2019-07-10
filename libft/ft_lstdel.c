/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 07:35:49 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/14 21:04:18 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next_lst;

	if (*alst == NULL || !alst || !del)
		return ;
	while (*alst)
	{
		next_lst = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free((*alst));
		*alst = NULL;
		*alst = next_lst;
	}
	*alst = NULL;
}
