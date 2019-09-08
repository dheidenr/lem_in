
#include "queue.h"
#include "exdlst.h"
#include "lem_in.h"
#include "aqueue.h"

void	initialize_bfs_search(graph *g)
{
	int 	i;

	i = 0;
//	while(i <= g->nvertices)
	while(i <= MAXV)
	{
		g->color[i] = WHITE;
		g->parents[i] = -1;
		i++;
	}
}

void	process_vertex_late(int v)
{

}

void process_vertex_early(int v)
{
//	printf("processed vertex %d\n", v);
}

void process_edge(int x, int y, graph *g)
{
//	printf("processed edge (%d, %d)\n", x, y);
	g->nedges++;
}
void	bfs(graph *g, int start)
{
	t_aqueue		*q;
	int			v;
	int 		y;
	t_edgenode *p;

	q = NULL;
	init_aqueue(&q);
	enaqueue(q, start);
	g->color[start] = WHITE;
	while (is_empty_aqueue(q) == FALSE)
	{
		v = deaqueue(q);
		process_vertex_early(v);
		g->color[v] = BLACK;
		p = g->edges[v];

//		while (p && p->isolate)
//			p = p->next;

		while (p != NULL)
		{

//			if (!p)
//				break ;
			y = p->y;
			if ((g->color[y] != BLACK) || (g->directed))
				process_edge(v, y, g);
			if (g->color[y] == WHITE && !p->isolate)
			{				enaqueue(q, y);
				g->color[y] = GRAY;
				g->parents[y] = v;
			}
			p = p->next;
		}
		process_vertex_late(v);
	}

	while((v = deaqueue(q), v != -1))
		;
	free(q);
}
