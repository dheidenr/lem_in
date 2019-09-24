/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:09:24 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/21 13:09:27 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*get_path(t_path *path, size_t step)
{
	t_path	*p;

	if (step == 0)
		return (path);
	if (!path)
		return (NULL);
	p = path;
	while (p && step > 0)
	{
		step--;
		p = p->next;
	}
	return (p);
}

void	print_ant_to_vertex(int ant, int vertex, t_context *context)
{
	putstr_free(strjoin_free("L", ft_itoa(ant), 2));
	putstr_free(ft_strjoin("-", context->names[(size_t)vertex]));
}

void	move_ant(t_path *src, t_path *dst, t_context *context)
{
	dst->ant = src->ant;
	if (src->ant != 0)
		print_ant_to_vertex(src->ant, dst->vertex, context);
}

void	offset_path(t_beam *beam, t_context *context)
{
	t_path	*p1;
	t_path	*p2;
	size_t	count;

	count = 0;
	if (get_path(beam->path, beam->length)->ant > 0)
		context->finish_ants++;
	while (count < beam->length)
	{
		p1 = get_path(beam->path, beam->length - count - 1);
		p2 = get_path(beam->path, beam->length - count);
		if (!p2)
			break ;
		if (context->flag && p1->ant != 0)
			ft_putchar(' ');
		if (p1->ant != 0)
			context->flag = 1;
		move_ant(p1, p2, context);
		count++;
	}
	beam->path->ant = 0;
}
