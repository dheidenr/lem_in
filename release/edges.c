/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edges.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:04:36 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/21 13:04:41 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	isolate_edgenode(t_edge *edgenode, char isolate)
{
	while (edgenode)
	{
		edgenode->isolate = isolate;
		edgenode = edgenode->next;
	}
}

void	isolate_all_edges(t_graph *g)
{
	size_t		count;
	t_edge		*edgenode;

	count = 1;
	while ((int)count <= g->nvertices)
	{
		edgenode = g->edges[count];
		while (edgenode)
		{
			edgenode->isolate = TRUE;
			edgenode = edgenode->next;
		}
		count++;
	}
}

void	turn_to_zero_all_edges(t_graph *g)
{
	size_t		count;
	t_edge		*edgenode;

	count = 1;
	while ((int)count <= g->nvertices)
	{
		edgenode = g->edges[count];
		while (edgenode)
		{
			edgenode->turn = FALSE;
			edgenode = edgenode->next;
		}
		count++;
	}
}
