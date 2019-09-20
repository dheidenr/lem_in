
#include "lem_in.h"

/*
** Удаление вершин из пути которые являются дубликатом оригинальной вершины
*/
void 	remove_fake_vertex(t_graph *g, t_context *context, int vertex, t_path **path)
{
	t_path	*prev;
	t_path	*tmp;
	t_path *start;

	start = *path;
	prev = *path;
	while (*path)
	{
		if (vertex == (*path)->vertex)
		{
			if (prev && prev == (*path))
			{
				*path = (*path)->next;
				free((prev));
				prev = NULL;
			}
			else if (prev && *path)
			{
				tmp = *path;
				if (prev->vertex != context->v_out[(*path)->vertex
												   - (g->nvertices - context->in_out_vertices)]
					&& (*path)->next->vertex != context->v_out[(*path)->vertex
															   - (g->nvertices - context->in_out_vertices)])
				{
					(*path)->vertex = (int)context->v_out[(*path)->vertex
														  - (g->nvertices - context->in_out_vertices)];
					*path = start;
					return ;
				}
				prev->next = (*path)->next;
				*path = start;
				if (tmp  != *path)
				{
					free((tmp));
					tmp = NULL;
				}
				return ;
			} else
				*path = NULL;
		} else
		{
			prev = *path;
			(*path) = (*path)->next;
		}
	}
}

void	remove_fake_vertexes(t_graph *g, t_context *context, t_path **path)
{
	t_path *tmp;

	tmp = *path;
	while(tmp)
	{
		if (tmp->vertex > g->nvertices - context->in_out_vertices)
		{
			remove_fake_vertex(g, context, tmp->vertex, path);
			tmp = *path;
		}
		tmp = tmp->next;
	}
}
