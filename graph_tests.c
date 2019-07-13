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