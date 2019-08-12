
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

