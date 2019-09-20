
#include "lem_in.h"

void	isolate_edgenode(t_edgenode *edgenode, char isolate)
{
	while (edgenode)
	{
		edgenode->isolate = isolate;
		edgenode = edgenode->next;
	}
}

void 	isolate_all_edges(t_graph *g)
{
	size_t 	count;
	t_edgenode	*edgenode;

	count = 1;
	while (count <= g->nvertices)
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

void 	turn_to_zero_all_edges(t_graph *g)
{
	size_t 	count;
	t_edgenode	*edgenode;

	count = 1;
	while (count <= g->nvertices)
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
