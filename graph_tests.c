#include "lem_in.h"

void	test_1_graph(graph *g, t_context *context, int directed)
{
	initialize_graph(g, context, directed);
	g->nvertices = 6;
	insert_edge(g, 1, 6, directed);
	insert_edge(g, 1, 2, directed);
	insert_edge(g, 2, 3, directed);
	insert_edge(g, 2, 5, directed);
	insert_edge(g, 3, 4, directed);
	insert_edge(g, 4, 5, directed);
	insert_edge(g, 5, 1, directed);

}

void	test_too_path_graph(graph *g, t_context *context, int directed)
{
	initialize_graph(g, context, directed);
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

void	test_24_4_graph_bellman_ford(graph *g, t_context *context, int directed)
{
	t_edgepoint ed;
	initialize_graph(g, context, directed);
	g->nvertices = 5;
	ed.x = 1;
	ed.y = 2;
	insert_edge_weight(g, &ed, directed, 6);
	ed.x = 1;
	ed.y = 4;
	insert_edge_weight(g, &ed, directed,7);
	ed.x = 2;
	ed.y = 3;
	insert_edge_weight(g, &ed, directed, 5);
	ed.x = 2;
	ed.y = 4;
	insert_edge_weight(g, &ed, directed, 8);
	ed.x = 2;
	ed.y = 5;
	insert_edge_weight(g, &ed, directed, -4);
	ed.x = 3;
	ed.y = 2;
	insert_edge_weight(g, &ed, directed, -2);
	ed.x = 4;
	ed.y = 3;
	insert_edge_weight(g, &ed, directed, -3);
	ed.x = 4;
	ed.y = 5;
	insert_edge_weight(g, &ed, directed, 9);
	ed.x = 5;
	ed.y = 1;
	insert_edge_weight(g, &ed, directed, 2);
	ed.x = 5;
	ed.y = 3;
	insert_edge_weight(g, &ed, directed, 7);
}

void	test_too_path_graph_suurballe(graph *g, t_context *context, int directed)
{
	initialize_graph(g, context, directed);
	g->nvertices = 6;
	insert_edge(g, 1, 2, directed);
	insert_edge(g, 1, 3, directed);
	insert_edge(g, 2, 4, directed);
//	insert_edge(g, 2, 3, directed);
	insert_edge(g, 2, 5, directed);
	insert_edge(g, 3, 4, directed);
	insert_edge(g, 4, 6, directed);
	insert_edge(g, 5, 6, directed);
}

void	test_too_path_graph_suurballe_extreme(graph *g, t_context *context, int directed)
{
	initialize_graph(g, context, directed);
	g->nvertices = 8;
	insert_edge(g, 1, 2, directed);
	insert_edge(g, 1, 3, directed);
	insert_edge(g, 2, 3, directed);
	insert_edge(g, 2, 4, directed);
	insert_edge(g, 3, 5, directed);
	insert_edge(g, 3, 6, directed);
	insert_edge(g, 4, 5, directed);
	insert_edge(g, 5, 8, directed);
	insert_edge(g, 6, 7, directed);
	insert_edge(g, 7, 8, directed);
}

void	test_too_path_graph_suurballe_wiki(graph *g, t_context *context, int directed)
{
	initialize_graph(g, context, directed);
	g->nvertices = 8;
	insert_edge(g, 1, 2, directed);
	insert_edge(g, 1, 5, directed);
	insert_edge(g, 2, 3, directed);
	insert_edge(g, 3, 4, directed);
	insert_edge(g, 4, 6, directed);
	insert_edge(g, 4, 8, directed);
	insert_edge(g, 4, 5, directed);
	insert_edge(g, 5, 6, directed);
	insert_edge(g, 6, 7, directed);
	insert_edge(g, 7, 8, directed);
}

void	test_three_path_graph_suurballe_little(graph *g, t_context *context, int directed)
{
	initialize_graph(g, context, directed);
	g->nvertices = 5;
	insert_edge(g, 1, 2, directed);
	insert_edge(g, 1, 3, directed);
	insert_edge(g, 1, 4, directed);
	insert_edge(g, 2, 5, directed);
	insert_edge(g, 3, 5, directed);
	insert_edge(g, 4, 5, directed);

	//update graph
	insert_edge(g, 2, 3, directed);
	insert_edge(g, 3, 4, directed);
}