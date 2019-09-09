
#include "lem_in.h"

void	clear_names(char **names)
{
	char **free_name;

	if (!names)
		return ;
	free_name = names;
	free_name++;
	while (*free_name)
	{
		free(*free_name);
		free_name++;
	}
	free(names);
}

void 	clear_edgenode(t_edgenode *edge)
{
	t_edgenode *free_edge;

	if (!edge)
		return ;
	free_edge = edge;
	while(edge)
	{
		edge = edge->next;
		free(free_edge);
		free_edge = NULL;
		free_edge = edge;
	}
}

void	clear_edges(t_edgenode **edges)
{
	t_edgenode **ed;
	size_t	count;

	count = 0;

	if (!edges)
		return ;
//	ed = edges;
	while(count < MAXV)
	{
		clear_edgenode(edges[count]);

//		edges++;
//		free(ed);
//		ed = NULL;
//		ed = edges;
		count++;
	}
//	free(edges);
}

void	clear_path(t_path *path)
{
	t_path *free_path;

	if (!path)
		return ;
	free_path = path;
	while(path)
	{
		path = path->next;
		free(free_path);
		free_path = NULL;
		free_path = path;
	}
}

void	clear_beam(t_beam *beam)
{
	t_beam *free_beam;

	if (!beam)
		return ;
	free_beam = beam;
	while(beam)
	{
		beam = beam->next;
		clear_path(free_beam->path);
		free_beam->path = NULL;
		free(free_beam);
		free_beam = NULL;
		free_beam = beam;
	}
	free(beam);
	beam = NULL;
}

void	clear_graph(graph *g)
{
	if (g)
		clear_edges(g->edges);
	free(g);
	g = NULL;

}

void	clearing_structures(graph *g, t_context *context, t_beam *beam)
{
	if (context)
	{
		clear_names(context->names);
		clear_edgenode(context->edgenode);
	}
	if (g)
		clear_edges(g->edges);
	clear_beam(beam);

}


