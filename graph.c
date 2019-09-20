
#include "lem_in.h"

void	initialize_graph(t_graph *g, t_context *context, int directed)
{
	int 	i;

	g->nvertices = 0;
	g->nedges = 0;
	g->directed = directed;
	i = 0;
	while (i <= MAXV)
	{
		g->degree[i] = 0;
		context->entry_time[i] = -1;
		context->exit_time[i] = -1;
		context->short_paths[i] = -1;
		g->edges[i] = NULL;
		i++;
	}
	context->in_out_vertices = 0;
	context->end = 0;
	context->start = 0;
	ft_memset(context->v_out, 0, sizeof(context->v_out));
	ft_memset(context->v_in, 0, sizeof(context->v_in));
	context->finish_ants = 0;
	context->global_ants = 0;
	context->edgenode = NULL;
	context->flag = 0;
}

int 	is_in_edges(t_edgenode *p, int y)
{
	t_edgenode *temp;

	temp = p;
	while(temp)
	{
		if  (temp->y == y)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	insert_edge(t_graph *g, int x, int y, int directed)
{
	t_edgenode *p;

	if (x == y)
		return ;
	if (g->edges[x])
		if (is_in_edges(g->edges[x], y))
			return ;
	p = malloc(sizeof(t_edgenode));
	p->weight = 1;
	p->turn = 0;
	p->isolate = FALSE;
	p->y = y;
	p->next = g->edges[x];
	g->edges[x] = p;
	g->degree[x]++;
	if (directed == FALSE)
		insert_edge(g, y, x, TRUE);
	else
		g->nedges++;
}

void	insert_edge_weight(t_graph *g, t_edgepoint *edgepoint, int directed, int weight)
{
	t_edgenode *p;

	if (edgepoint->x == edgepoint->y)
		return ;
	if (g->edges[edgepoint->x])
		if (is_in_edges(g->edges[edgepoint->x], edgepoint->y))
			return ;
	p = ft_memalloc(sizeof(t_edgenode));
	p->weight = weight;
	p->turn = 0;
	p->isolate = FALSE;
	p->y = edgepoint->y;
	p->next = g->edges[edgepoint->x];
	g->edges[edgepoint->x] = p;
	g->degree[edgepoint->x]++;
	if (directed == FALSE)
		insert_edge_weight(g, edgepoint, TRUE, weight);
	else
		g->nedges++;
}

void	print_graph(t_graph *g)
{
	int 	i;
	t_edgenode *p;

	i = 1;
	while(i <= g->nvertices)
	{
		printf("%d: ", i);
		p = g->edges[i];
		while (p != NULL)
		{
			printf(" %d(w:%d,t:%d,i:%d)", p->y, p->weight, p->turn, p->isolate);
			p = p->next;
		}
		printf("\n");
		i++;
	}
}
