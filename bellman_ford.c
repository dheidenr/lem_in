
#include "lem_in.h"
#include "libft.h"
#include "queue.h"
#include "exdlst.h"


void	initialize_bellman_ford_search(graph *g, t_context* context, int start)
{
	int 	i;

	i = 0;
	while(i <= MAXV)
	{
		g->color[i] = WHITE;
		g->parent[i] = -1;
		context->entry_time[i] = -1;
		context->exit_time[i] = -1;
		context->exit_time[i] = -1;
		context->short_paths[i] = INT_MAX;
		i++;
	}
	g->finished = FALSE;
	context->short_paths[start] = 0;
	context->short_paths[0] = 0;
}

void	relax(graph *g, t_context *context, int current_vertex, int prev_vertex)
{
	if (context->short_paths[current_vertex] > context->short_paths[prev_vertex]
				+ context->edgenode->weight)
	{
		context->short_paths[current_vertex] = context->short_paths[prev_vertex]
				+ context->edgenode->weight;
		g->parent[current_vertex] = prev_vertex;
	}
}

int		bellman_ford(graph *g, t_context *context, int start)
{
	int				i;
	int 				j;
	t_edgenode		*p;

	j = 1;
	initialize_bellman_ford_search(g, context, start);

	while (j < g->nvertices - 1)
	{
		i = 1;
		while (i <= g->nvertices)
		{
			p = g->edges[i];
			while (p)
			{
				context->edgenode = p;
				relax(g, context, p->y,  i);
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
			if (context->short_paths[i] > context->short_paths[i - 1] + p->weight)
				return (FALSE);
			p = p->next;
		}
		i++;
	}
	return (TRUE);
}
