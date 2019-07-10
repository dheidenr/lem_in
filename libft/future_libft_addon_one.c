/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   future_libft_addon_one.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:54:57 by dheidenr          #+#    #+#             */
/*   Updated: 2019/06/20 13:55:00 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strjoin_free(char *s1, char *s2, int clear_number)
{
	char *tmp;

	tmp = ft_strjoin(s1, s2);
	if (clear_number == 0 ||
		clear_number == 12)
	{
		free(s1);
		free(s2);
	}
	if (clear_number == 1)
		free(s1);
	if (clear_number == 2)
		free(s2);
	return (tmp);
}

void	ft_dlistsput(t_dlist *stack1, t_dlist *stack2)
{
	while (stack2 || stack1)
	{
		if (stack1)
		{
			ft_putnbr(*(int *)stack1->content);
			ft_putchar(' ');
			stack1 = stack1->next;
		}
		else
			ft_putstr("    ");
		if (stack2)
		{
			if (stack2->content)
			{
				ft_putnbr(*(int *)stack2->content);
				ft_putchar(' ');
			}
			stack2 = stack2->next;
		}
		else
			ft_putstr("    ");
		ft_putchar('\n');
	}
	ft_putstr("_   _\n");
}

void	ft_dlstdelone(t_dlist **adlst, void (*del)(void*, size_t))
{
	if (*adlst == NULL || !adlst || !del)
		return ;
	del((*adlst)->content, (*adlst)->content_size);
	ft_memdel((void **)adlst);
}

int		ft_putstr_return(const char *str, int result)
{
	if (!str)
		return (0);
	write(2, str, ft_strlen(str));
	return (result);
}
