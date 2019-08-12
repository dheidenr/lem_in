
#include "lem_in.h"

void	remove_edge_directed(graph *g, int x, int y)
{
	t_edgenode *edge;
	t_edgenode *prevedge;
	char 		oneflag;

	oneflag = 1;
	edge = g->edges[x];
	prevedge = edge;
	while(edge)
	{
		if (edge->y == y)
		{
			if (oneflag)
			{
				prevedge = edge->next;
				free(edge);
				edge = NULL;
				g->edges[x] = prevedge;
			} else
			{
				prevedge->next = edge->next;
				free(edge);
				edge = NULL;
			}
			break;
		}
		prevedge = edge;
		edge = edge->next;
		oneflag = 0;
	}
}

void	remove_edge(graph *g, t_edgepoint edgepoint, int directed)
{
	remove_edge_directed(g, edgepoint.x, edgepoint.y);
	if (directed == FALSE)
		remove_edge_directed(g, edgepoint.y, edgepoint.x);
}

int 	get_weight_edge(graph *g, t_edgepoint *edp)
{
	t_edgenode *edgenode;

	edgenode = g->edges[edp->x];
	while(edgenode)
	{
		if (edgenode->y == edp->y)
			return (edgenode->weight);
		edgenode = edgenode->next;
	}
	return (0);
}

void	reverse_edge_and_weight(graph *g, t_edgepoint edp)
{
	t_edgepoint reversive_edge;

	reversive_edge.x = edp.y;
	reversive_edge.y = edp.x;

	insert_edge_weight(g, &reversive_edge, TRUE, -get_weight_edge(g, &edp));
	remove_edge(g, edp, TRUE);
}
