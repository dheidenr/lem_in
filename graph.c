
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

void	insert_edge(graph *g, int x, int y, int directed)
{
	edgenode *p;

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
	printf("input please d and d for nvertices");
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

void	random_graph(graph *g, int directed)
{
	int 	i;
	int 	m;
	int 	x, y;

	initialize_graph(g, directed);
	g->nvertices = 255;
	m = 255;
	i = 1;
	while(i <= m)
	{
		x = (unsigned char)random();
		y = (unsigned char)random();
		insert_edge(g, x, y, directed);
		i++;
	}
}
