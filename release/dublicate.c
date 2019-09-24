/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dublicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:03:56 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/21 13:04:01 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Фукнция дублирования вершин через:
** вставку нового ребра
** удаление старого ребра
** по циклу
*/

void	duplicate_vertex(t_graph *g, t_context *context, int vertex)
{
	t_edgepoint		edgepoint;
	t_edge			*edgenode;
	t_edge			*edtemp;

	context->v_in[vertex] = TRUE;
	g->nvertices++;
	context->in_out_vertices++;
	context->v_out[context->in_out_vertices] = vertex;
	edgepoint.x = vertex;
	edgepoint.y = g->nvertices;
	insert_edge_weight(g, &edgepoint, TRUE, 0);
	edgenode = g->edges[vertex]->next;
	while (edgenode)
	{
		edgepoint.x = g->nvertices;
		edgepoint.y = edgenode->y;
		insert_edge_weight(g, &edgepoint, TRUE, edgenode->weight);
		edtemp = get_edgenode(g, &edgepoint);
		edtemp->turn = edgenode->turn;
		edgepoint.x = vertex;
		remove_edge(g, edgepoint, TRUE);
		edgenode = g->edges[vertex]->next;
		if (edgenode)
			edgenode = edgenode->next;
	}
}

/*
** Дублирование всех вершин кроме начала и конца
*/

void	duplicate_all_vertexes_graph(
		t_graph *g, t_context *context, int start, int end)
{
	int		vertex;

	vertex = 1;
	while (vertex < g->nvertices - context->in_out_vertices)
	{
		if (vertex != start && vertex != end && !context->v_in[vertex])
			duplicate_vertex(g, context, vertex);
		vertex++;
	}
}

void	reverse_path(t_graph *g, t_path *path)
{
	t_edgepoint edgepoint;

	if (!path)
		return ;
	while (path->next)
	{
		edgepoint.x = path->vertex;
		edgepoint.y = path->next->vertex;
		reverse_edge_and_weight(g, edgepoint);
		path = path->next;
	}
}
