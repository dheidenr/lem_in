
#include "lem_in.h"
#include "libft.h"
#include "queue.h"
#include "exdlst.h"

void	dijkstra(graph *g, int start)
{
	int		i;
	t_edgenode *p;
	unsigned char intree[MAXV + 1];
	int 	distance[MAXV + 1];
	int		v;
	int 	w;
	int 	weight;
	int 	dist;

	i = 1;
	while(i <= g->nvertices)
	{
		intree[i] = FALSE;
		distance[i] = INT_MAX;
		g->parent[i] = -1;
	}
	distance[start] = 0;
	v = start;
	while(intree[v] == FALSE)
	{
		intree[v] = TRUE;
		p = g->edges[v];
		while (p != NULL)
		{
			w = p->y;
			weight = p->weight;
			if (distance[w] > (distance[w] + weight))
			{
				distance[w] = distance[w] + weight;
				g->parent[w] = v;
			}
			p = p->next;
		}
		i = 1;
		v = 1;
		dist = INT_MAX;
		while(i <= g->nvertices)
		{
			if (intree[i] == FALSE && dist > distance[i])
			{
				dist = distance[i];
				v = i;
			}
		}
	}
}