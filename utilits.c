
#include "lem_in.h"

int 	get_turn_edge(graph *g, t_edgepoint *edp)
{
	t_edgenode *edgenode;

	edgenode = g->edges[edp->x];
	while(edgenode)
	{
		if (edgenode->y == edp->y)
			return (edgenode->turn);
		edgenode = edgenode->next;
	}
	return (0);
}

t_path	*find_path(int start, int end, int parents[], t_path **path)
{
	if (start == end || end == -1)
		add_vertex_to_path(path, start);
	else
	{
		if (parents[end] == -1)
			return (NULL);
		find_path(start, parents[end], parents, path);
		add_vertex_to_path(path, end);
	}
	return (*path);
}
