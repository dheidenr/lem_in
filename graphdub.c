
#include "lem_in.h"

void	initialize_only_graph(graph *g, int directed)
{
	int 	i;

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

graph*	graphdub(graph* g)
{
	graph 			*graph_result;
	t_edgepoint ed;
	t_edgenode *edgenode;
	t_edgenode *tmp_edge;
	size_t				i;


	graph_result =  (graph *)malloc(sizeof(*g));

	initialize_only_graph(graph_result, g->directed);
	i = 0;
	while(i <= g->nvertices)
	{
		edgenode = g->edges[i];
		ed.x = i;
		while(edgenode)
		{
			ed.y = edgenode->y;
			insert_edge_weight(graph_result, &ed, g->directed, edgenode->weight);
			tmp_edge = get_edgenode(graph_result, &ed);
			tmp_edge->isolate = edgenode->isolate;
			edgenode = edgenode->next;
		}
		i++;
	}
	graph_result->directed = g->directed;
	graph_result->nvertices = g->nvertices;
	graph_result->nedges = g->nedges;
	i = 0;
	while (i <= MAXV)
	{
		graph_result->degree[i] = g->degree[i];
		i++;
	}
	return (graph_result);
}
