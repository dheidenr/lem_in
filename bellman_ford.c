
#include "lem_in.h"
#include "libft.h"
#include "queue.h"
#include "exdlst.h"


void	initialize_bellman_ford_search(graph *g, int start)
{
	int 	i;

	i = 0;
	while(i <= MAXV)
	{
		g->color[i] = WHITE;
		g->parent[i] = -1;
		g->entry_time[i] = -1;
		g->exit_time[i] = -1;
		g->exit_time[i] = -1;
		g->short_paths[i] = INT_MAX;
		i++;
	}
	g->finished = FALSE;
	g->short_paths[start] = 0;
	g->short_paths[0] = 0;
}

void	relax(graph *g, t_edgenode *u, int current_vertex, int prev_vertex)
{
	if (g->short_paths[current_vertex] > g->short_paths[prev_vertex] + u->weight)
	{
		g->short_paths[current_vertex] = g->short_paths[prev_vertex] + u->weight;
		g->parent[current_vertex] = prev_vertex;
	}
}

int		bellman_ford(graph *g, int start)
{
	int				i;
	int 				j;
	t_edgenode		*p;

	j = 1;
	initialize_bellman_ford_search(g, start);

	while (j < g->nvertices - 1)
	{
		i = 1;
		while (i <= g->nvertices)
		{
			p = g->edges[i];
			while (p)
			{
				relax(g, p, p->y,  i);
				p = p->next;
			}
			i++;
		}
		j++;
	}
	i = 1;
	while (i < g->nvertices)
	{
		p = g->edges[i];
		while (p)
		{
			if (g->short_paths[i] > g->short_paths[i - 1] + p->weight)
				return (FALSE);
			p = p->next;
		}
		i++;
	}
	return (TRUE);
}
