/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:04:08 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/21 13:04:11 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	processor_step_one(t_support_edge *sup, t_graph *g, t_edgepoint *p)
{
	if (sup->flag)
	{
		sup->prev_edge = sup->edge->next;
		free(sup->edge);
		sup->edge = NULL;
		g->edges[p->x] = sup->prev_edge;
	}
	else
	{
		sup->prev_edge->next = sup->edge->next;
		free(sup->edge);
		sup->edge = NULL;
	}
}

void	remove_edge_directed(t_graph *g, t_edgepoint *p)
{
	t_support_edge sup;

	sup.flag = 1;
	sup.edge = g->edges[p->x];
	sup.prev_edge = sup.edge;
	while (sup.edge)
	{
		if (sup.edge->y == p->y)
		{
			processor_step_one(&sup, g, p);
			--g->nedges;
			return ;
		}
		sup.prev_edge = sup.edge;
		sup.edge = sup.edge->next;
		sup.flag = 0;
	}
}

void	remove_edge(t_graph *g, t_edgepoint edgepoint, int directed)
{
	remove_edge_directed(g, &edgepoint);
	if (directed == FALSE)
		remove_edge_directed(g, &edgepoint);
}

int		get_weight_edge(t_graph *g, t_edgepoint *edp)
{
	t_edgenode *edgenode;

	edgenode = g->edges[edp->x];
	while (edgenode)
	{
		if (edgenode->y == edp->y)
			return (edgenode->weight);
		edgenode = edgenode->next;
	}
	return (0);
}
