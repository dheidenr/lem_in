/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   future_libft_addon_three.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 17:26:38 by dheidenr          #+#    #+#             */
/*   Updated: 2019/06/29 17:29:37 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		equiv_max_template(char *src, char *template)
{
	int		not_max_template;
	char	*tmp;

	not_max_template = 0;
	tmp = src;
	while (*tmp)
	{
		if (*tmp != template[ft_strlen(template) - 1])
			not_max_template += 1;
		tmp++;
	}
	if (!not_max_template)
		return (1);
	return (0);
}

void	brute_force_one_symbol(char *elements, char *template)
{
	char	*symbol;

	symbol = elements + ft_strlen(elements) - 1;
	if (!ft_strlen(symbol))
		return ;
	ft_putstr(elements);
	ft_putchar('\n');
	if (equiv_max_template(elements, template))
		return ;
	while (ft_strlen(symbol))
	{
		if (*symbol >= template[ft_strlen(template) - 1])
			*symbol = template[0];
		else
		{
			*symbol = *(ft_strchr(template, *symbol) + 1);
			break ;
		}
		symbol--;
	}
	brute_force_one_symbol(elements, template);
}

void	dlist_int_put_in_cycle(t_dlist *dlist)
{
	ft_putstr("dlist_content:|");
	ft_putnbr(*(int *)dlist->content);
	ft_putstr("| ");
	if (dlist->next)
	{
		ft_putstr("dlist->next:|Yes  ");
		ft_putnbr(*(int *)dlist->next->content);
		ft_putchar('|');
	}
	else
		ft_putstr("dlist->next:|Null| ");
	if (dlist->prev)
	{
		ft_putstr("dlist->prev:|Yes  ");
		ft_putnbr(*(int *)dlist->prev->content);
		ft_putchar('|');
	}
	else
		ft_putstr("dlist->prev:|Null| ");
}

void	dlist_int_put(t_dlist *dlist)
{
	ft_putchar('\n');
	ft_putstr(__func__);
	ft_putstr("\nstep of next->\n");
	while (dlist)
	{
		dlist_int_put_in_cycle(dlist);
		dlist = dlist->next;
		ft_putstr("\n");
	}
}

int		check_equallity(t_dlist *input, t_dlist *sorted)
{
	while (input && sorted)
	{
		if (*(int *)input->content != *(int *)sorted->content)
			return (0);
		input = input->next;
		sorted = sorted->next;
	}
	if (input != NULL || sorted != NULL)
		return (0);
	return (1);
}
