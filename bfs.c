
#include "exdlst.h"
#include "lem_in.h"
#include "aqueue.h"

void	initialize_bfs_search(graph *g)
{
	int 	i;

	i = 0;
	while(i <= MAXV)
	{
		g->color[i] = WHITE;
		g->parents[i] = -1;
		i++;
	}
}

void process_edge(graph *g)
{
	g->nedges++;
}

void	cycle_bfs(t_bfs *b, graph *g, int *y, const int *v)
{
	while (b->p != NULL)
	{
		(*y) = b->p->y;
		if ((g->color[(*y)] != BLACK) || (g->directed))
			process_edge(g);
		if (g->color[(*y)] == WHITE && !b->p->isolate)
		{
			enaqueue(b->q, (*y));
			g->color[(*y)] = GRAY;
			g->parents[(*y)] = (*v);
		}
		b->p = b->p->next;
	}
}

void	bfs(graph *g, int start)
{
	int				v;
	int 			y;
	t_bfs			b;

	b.q = NULL;
	init_aqueue(&(b.q));
	enaqueue(b.q, start);
	g->color[start] = WHITE;
	while (is_empty_aqueue(b.q) == FALSE)
	{
		v = deaqueue(b.q);
		g->color[v] = BLACK;
		b.p = g->edges[v];
		cycle_bfs(&b, g, &y, &v);
	}
	while((v = deaqueue(b.q), v != -1))
		;
	free(b.q);
}
