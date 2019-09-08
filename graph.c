
#include "lem_in.h"

void	initialize_graph(graph *g, t_context *context, int directed)
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
	context->in_out_vertices = 0;
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

void	insert_edge(graph *g, int x, int y, int directed)
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

void	insert_edge_weight(graph *g, t_edgepoint *edgepoint, int directed, int weight)
{
	t_edgenode *p;

	if (edgepoint->x == edgepoint->y)
		return ;
	if (g->edges[edgepoint->x])
		if (is_in_edges(g->edges[edgepoint->x], edgepoint->y))
			return ;
	p = malloc(sizeof(t_edgenode));
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

void	print_graph(graph *g)
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

void	read_graph(graph *g, t_context *context, int directed)
{
	int 	i;
	int 	m;
	int 	x, y;

	initialize_graph(g, context, directed);
	printf("input please nvertices and edges");
	scanf("%d %d", &(g->nvertices), &m);
	i = 1;
	while(i <= m)
	{
		printf("input please x and y for insert_edge");
		scanf("%d %d", &x, &y);
		insert_edge(g, x, y, directed);
		i++;
	}
}

void	random_graph(graph *g, t_context *context, int directed, int nvertices, unsigned int r, int edges)
{
	int 	i;
	int 	m;
	int 	x, y;

	initialize_graph(g, context, directed);
	g->nvertices = nvertices;
	m = edges;
	i = 1;
	while(i <= m)
	{
		x = (unsigned int)random() % r;
		y = (unsigned int)random()  % r;
		insert_edge(g, x, y, directed);
		i++;
	}
}
