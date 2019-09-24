/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphdub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:07:22 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/21 13:07:32 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		initialize_only_graph(t_graph *g, int directed)
{
	int		i;

	g->nvertices = 0;
	g->nedges = 0;
	g->directed = directed;
	i = 0;
	while (i <= MAXV)
	{
		g->degree[i] = 0;
		g->edges[i] = NULL;
		i++;
	}
}

void		copy_degree_and_properties(t_graph *graph_result, t_graph *g)
{
	size_t	i;

	i = 0;
	graph_result->directed = g->directed;
	graph_result->nvertices = g->nvertices;
	graph_result->nedges = g->nedges;
	while (i <= MAXV)
	{
		graph_result->degree[i] = g->degree[i];
		i++;
	}
}

t_graph		*graphdub(t_graph *g)
{
	t_graph		*graph_result;
	t_edgepoint	ed;
	t_edge		*edge;
	t_edge		*tmp_edge;
	size_t		i;

	graph_result = (t_graph *)malloc(sizeof(t_graph));
	initialize_only_graph(graph_result, g->directed);
	i = 0;
	while ((int)i <= g->nvertices)
	{
		edge = g->edges[i];
		ed.x = i;
		while (edge)
		{
			ed.y = edge->y;
			insert_edge_weight(graph_result, &ed, g->directed, edge->weight);
			tmp_edge = get_edgenode(graph_result, &ed);
			tmp_edge->isolate = edge->isolate;
			edge = edge->next;
		}
		i++;
	}
	copy_degree_and_properties(graph_result, g);
	return (graph_result);
}
