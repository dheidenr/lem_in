
#include "lem_in.h"

void	initialize_graph(graph *g, int directed)
{
	int 	i;

	g->nvertices = 0;
	g->nedges = 0;
	g->directed = directed;
	i = 1;
	while (i <= MAXV)
	{
		g->degree[i] = 0;
		g->edges[i] = NULL;
		i++;
	}
}

int 	is_in_edges(edgenode *p, int y)
{
	edgenode *temp;

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
	edgenode *p;

	if (x == y)
		return ;
	if (g->edges[x])
		if (is_in_edges(g->edges[x], y))
			return ;
	p = malloc(sizeof(edgenode));
	p->weight = NULL;
	p->y = y;
	p->next = g->edges[x];
	g->edges[x] = p;
	g->degree[x]++;
	if (directed == FALSE)
		insert_edge(g, y, x, TRUE);
	else
		g->nedges++;
}

void	print_graph(graph *g)
{
	int 	i;
	edgenode *p;

	i = 1;
	while(i <= g->nvertices)
	{
		printf("%d: ", i);
		p = g->edges[i];
		while (p != NULL)
		{
			printf(" %d", p->y);
			p = p->next;
		}
		printf("\n");
		i++;
	}
}

void	read_graph(graph *g, int directed)
{
	int 	i;
	int 	m;
	int 	x, y;

	initialize_graph(g, directed);
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

void	random_graph(graph *g, int directed, int nvertices, unsigned char r, int edges)
{
	int 	i;
	int 	m;
	int 	x, y;

	initialize_graph(g, directed);
	g->nvertices = nvertices;
	m = edges;
	i = 1;
	while(i <= m)
	{
		x = (unsigned char)random() % r;
		y = (unsigned char)random()  % r;
		insert_edge(g, x, y, directed);
		i++;
	}
}
