#include "lem_in.h"

void	test_1_graph(graph *g, int directed)
{
	initialize_graph(g, directed);
	g->nvertices = 6;
	insert_edge(g, 1, 6, directed);
	insert_edge(g, 1, 2, directed);
	insert_edge(g, 2, 3, directed);
	insert_edge(g, 2, 5, directed);
	insert_edge(g, 3, 4, directed);
	insert_edge(g, 4, 5, directed);
	insert_edge(g, 5, 1, directed);

}

void	test_too_path_graph(graph *g, int directed)
{
	initialize_graph(g, directed);
	g->nvertices = 6;
	insert_edge(g, 1, 2, directed);
	insert_edge(g, 1, 3, directed);
	insert_edge(g, 1, 4, directed);
	insert_edge(g, 2, 3, directed);
	insert_edge(g, 2, 4, directed);
	insert_edge(g, 3, 6, directed);
	insert_edge(g, 3, 5, directed);
	insert_edge(g, 4, 5, directed);
	insert_edge(g, 4, 6, directed);
	insert_edge(g, 5, 6, directed);
}

void	test_24_4_graph_bellman_ford(graph *g, int directed)
{
	initialize_graph(g, directed);
	g->nvertices = 5;
	insert_edge_weight(g, 1, 2, directed, 6);
	insert_edge_weight(g, 1, 4, directed, 7);
	insert_edge_weight(g, 2, 3, directed, 5);
	insert_edge_weight(g, 2, 4, directed, 8);
	insert_edge_weight(g, 2, 5, directed, -4);
	insert_edge_weight(g, 3, 2, directed, -2);
	insert_edge_weight(g, 4, 3, directed, -3);
	insert_edge_weight(g, 4, 5, directed, 9);
	insert_edge_weight(g, 5, 1, directed, 2);
	insert_edge_weight(g, 5, 3, directed, 7);
}