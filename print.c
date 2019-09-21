/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:09:45 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/21 13:09:48 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_path(t_path *path)
{
	while (path)
	{
		ft_putstr(" ");
		ft_putnbr(path->vertex);
		path = path->next;
	}
	ft_putstr("\n");
}

void	print_beam(t_beam *beam)
{
	int		count;
	char	*str;

	count = 1;
	while (beam)
	{
		str = ft_itoa(count);
		putstr_free(str);
		ft_putstr(":");
		str = ft_itoa(beam->ants);
		putstr_free(str);
		ft_putstr(" ants:");
		str = ft_itoa(beam->length);
		putstr_free(str);
		ft_putstr(" length:");
		if (beam->path)
			print_path(beam->path);
		beam = beam->next;
		++count;
	}
	ft_putstr("\n");
}

void	print_array_graph(int *array, t_graph *g, char *str)
{
	int		i;

	i = 0;
	ft_putstr(str);
	while (++i <= MAXV)
	{
		ft_putstr(" ");
		ft_putnbr(array[i]);
		if (array[i] == -1 && i > g->nvertices)
			break ;
	}
	ft_putstr("\n");
}
