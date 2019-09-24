/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exdlst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:04:49 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/21 13:04:52 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "exdlst.h"

void	exdlist_int_put_next_prev(t_exdlist *exdlist)
{
	ft_putstr("dlist_content:|");
	ft_putnbr(*(int *)exdlist->content);
	ft_putstr("| ");
	if (exdlist->next)
	{
		ft_putstr("dlist->next:|Yes ");
		ft_putnbr(*(int *)exdlist->next->content);
		ft_putchar('|');
	}
	else
		ft_putstr("dlist->next:|NULL| ");
	if (exdlist->prev)
	{
		ft_putstr("dlist->prev:|Yes ");
		ft_putnbr(*(int *)exdlist->prev->content);
		ft_putchar('|');
	}
	else
		ft_putstr("dlist->prev:|NULL| ");
}

void	exdlist_int_put_start_end(t_exdlist *exdlist)
{
	if (exdlist->start)
	{
		ft_putstr("dlist->start:|Yes ");
		ft_putnbr(*(int *)exdlist->start->content);
		ft_putchar('|');
	}
	else
		ft_putstr("dlist->start:|NULL| ");
	if (exdlist->end)
	{
		ft_putstr("dlist->end:|Yes ");
		ft_putnbr(*(int *)exdlist->end->content);
		ft_putchar('|');
	}
	else
		ft_putstr("dlist->end:|NULL| ");
}

void	exdlist_int_put(t_exdlist *exdlist)
{
	if (!exdlist)
		ft_putstr("NULL\n");
	while (exdlist)
	{
		exdlist_int_put_next_prev(exdlist);
		exdlist_int_put_start_end(exdlist);
		exdlist = exdlist->next;
		ft_putstr("\n");
	}
}
