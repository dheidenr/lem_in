/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:09:53 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/21 13:09:56 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_not_clone(
		t_path *prev, t_compact *comp, t_path **path, t_path **start)
{
	if (prev->vertex != comp->c->v_out[(*path)->vertex
		- (comp->g->nvertices - comp->c->in_out_vertices)]
		&& (*path)->next->vertex != comp->c->v_out[(*path)->vertex
		- (comp->g->nvertices - comp->c->in_out_vertices)])
	{
		(*path)->vertex = (int)comp->c->v_out[(*path)->vertex
		- (comp->g->nvertices - comp->c->in_out_vertices)];
		*path = *start;
		return (1);
	}
	return (0);
}

int		complite_rmove(
		t_path **prev, t_compact *comp, t_path **path, t_path **start)
{
	t_path	*tmp;

	if (*prev && *prev == (*path))
	{
		*path = (*path)->next;
		free((*prev));
		*prev = NULL;
	}
	else if (*prev && *path)
	{
		tmp = *path;
		if (is_not_clone(*prev, comp, path, start))
			return (1);
		(*prev)->next = (*path)->next;
		*path = *start;
		if (tmp != *path)
			free((tmp));
		return (1);
	}
	else
		*path = NULL;
	return (0);
}

/*
** Удаление вершин из пути которые являются дубликатом оригинальной вершины
*/

void	remove_fake_vertex(
		t_graph *g, t_context *context, int vertex, t_path **path)
{
	t_path		*prev;
	t_path		*start;
	t_compact	comp;

	comp.g = g;
	comp.c = context;
	start = *path;
	prev = *path;
	while (*path)
	{
		if (vertex == (*path)->vertex)
		{
			if (complite_rmove(&prev, &comp, path, &start))
				return ;
		}
		else
		{
			prev = *path;
			(*path) = (*path)->next;
		}
	}
}

void	remove_fake_vertexes(t_graph *g, t_context *context, t_path **path)
{
	t_path	*tmp;

	tmp = *path;
	while (tmp)
	{
		if (tmp->vertex > g->nvertices - context->in_out_vertices)
		{
			remove_fake_vertex(g, context, tmp->vertex, path);
			tmp = *path;
		}
		tmp = tmp->next;
	}
}
