
#include "queue.h"
#include "exdlst.h"
#include "lem_in.h"

int 	time_count;

void	initialize_dfs_search(graph *g, t_context *context)
{
	int 	i;

	i = 0;
	time_count = 0;
//	while(i <= g->nvertices)
	while(i <= MAXV)
	{
		g->color[i] = WHITE;
		g->parents[i] = -1;
		context->entry_time[i] = -1;
		context->exit_time[i] = -1;
		i++;
	}
	g->finished = FALSE;
}

void	process_dfs_vertex_late(int v)
{

}

void process_dfs_vertex_early(int v)
{
	printf("processed vertex %d\n", v);
}

void process_dfs_edge(int x, int y, graph *g)
{
	printf("processed edge (%d, %d)\n", x, y);
	g->nedges++;
//	if (g->parents[x] != y)
//	{
//		printf("cycle from %d to %d:", y, x);
//		printf("\n\n");
//		g->finished = TRUE;
//	}
}
void	dfs(graph *g, t_context *context, int v)
{
	t_edgenode		*p;
	int 						y;

	if (g->finished == TRUE)
		return ;
	g->color[v] = GRAY;
	time_count++;
	context->entry_time[v] = time_count;
	process_dfs_vertex_early(v);
	p = g->edges[v];
	while (p != NULL)
	{
		y = p->y;
		if (g->color[y] == WHITE)
		{
			g->parents[y] = v;
			process_dfs_edge(v, y, g);
			dfs(g, context, y);
		}
		else if ((g->color[y] != BLACK) || (g->directed))
			process_dfs_edge(v, y, g);
		if (g->finished == TRUE)
			return ;
		p = p->next;
	}
	process_dfs_vertex_late(v);
	time_count++;
	context->exit_time[v] = time_count;
	g->color[v] = BLACK;
}

void	dfs_visit(graph *g, t_context *context, int v)
{
	t_edgenode *p;
	int y;
//	if (g->finished == TRUE)
//		return ;
	time_count++;
	context->entry_time[v] = time_count;
	g->color[v] = GRAY;
//	process_dfs_vertex_early(v);
	p = g->edges[v];
	while (p != NULL)
	{
		y = p->y;
		if (g->color[y] == WHITE)
		{
			g->parents[y] = v;
//			process_dfs_edge(v, y, g);
			dfs_visit(g, context, y);
		}
		else if ((g->color[y] != BLACK) || (g->directed))
			process_dfs_edge(v, y, g);
//		if (g->finished == TRUE)
//			return ;
		p = p->next;
	}
	process_dfs_vertex_late(v);
	g->color[v] = BLACK;
	time_count++;
	context->exit_time[v] = time_count;
}

void	dfs2(graph *g, t_context *context, int v)
{
	int i;

	i = 1;
	while (i <= g->nvertices)
	{
		if (g->color[i] == WHITE)
			dfs_visit(g,context,  v);
		i++;
	}
}
