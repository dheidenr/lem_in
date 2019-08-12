


#include "lem_in.h"
#include "libft.h"
#include "queue.h"
#include "exdlst.h"


void	initialize_suurballe_search(graph *g, t_context* context)
{
	int 	i;

	i = 0;
	while(i <= MAXV)
	{
		g->color[i] = WHITE;
		g->parents[i] = -1;
		context->entry_time[i] = -1; //Можно будет убрать из структуры в функцию
		context->exit_time[i] = -1; //Можно будет убрать из структуры в функцию
		i++;
	}
	g->finished = FALSE;
}

graph*	graphdub(graph* g)
{
	graph 			*graph_result;
	t_edgepoint ed;
	t_edgenode *edgenode;
	size_t				i;

	graph_result =  (graph *)malloc(sizeof(*g));
	i = 0;
	while(i <= g->nvertices)
	{
		edgenode = g->edges[i];
		ed.x = i;
		while(edgenode)
		{
			ed.y = edgenode->y;
			insert_edge_weight(graph_result, &ed, g->directed, edgenode->weight);
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

void	suurballe(graph *g, int start, int end)
{
	int				i;
	t_edgenode		*p;
	unsigned char	intree[MAXV + 1];
	int			 	distance[MAXV + 1];
	int				v;
	int 			w;
	int 			weight;
	int 			dist;
	graph	*gdub;
	//Zero step Suurballe
	gdub = graphdub(g);
	//One step of algorithm Suurballe
	dijkstra(gdub, start);
	//Two step




}
