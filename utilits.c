
#include "lem_in.h"

void	remove_edge_directed(graph *g, int x, int y)
{
	t_edgenode *edge;
	t_edgenode *prevedge;
	char 		oneflag;

	oneflag = 1;
	edge = g->edges[x];
	prevedge = edge;
	while(edge)
	{
		if (edge->y == y)
		{
			if (oneflag)
			{
				prevedge = edge->next;
				free(edge);
				edge = NULL;
				g->edges[x] = prevedge;
			} else
			{
				prevedge->next = edge->next;
				free(edge);
				edge = NULL;
			}
			--g->nedges;
			break;
		}
		prevedge = edge;
		edge = edge->next;
		oneflag = 0;
	}
}

void	remove_edge(graph *g, t_edgepoint edgepoint, int directed)
{
	remove_edge_directed(g, edgepoint.x, edgepoint.y);
	if (directed == FALSE)
		remove_edge_directed(g, edgepoint.y, edgepoint.x);
}

int 	get_weight_edge(graph *g, t_edgepoint *edp)
{
	t_edgenode *edgenode;

	edgenode = g->edges[edp->x];
	while(edgenode)
	{
		if (edgenode->y == edp->y)
			return (edgenode->weight);
		edgenode = edgenode->next;
	}
	return (0);
}

void	reverse_edge_and_weight(graph *g, t_edgepoint edp)
{
	t_edgepoint reversive_edge;

	reversive_edge.x = edp.y;
	reversive_edge.y = edp.x;
	insert_edge_weight(g, &reversive_edge, TRUE, -get_weight_edge(g, &edp));
	remove_edge(g, edp, TRUE);
}

void	add_path_to_beam(t_beam **beam, t_path **path)
{
	t_beam		*beamtemp;

	if (!*beam)
	{
		*beam = (t_beam *) malloc(sizeof(t_beam));
		(*beam)->next = NULL;
		(*beam)->path = *path;
	} else
	{
		while ((*beam)->next)
			*beam = (*beam)->next;
		beamtemp = (t_beam *) malloc(sizeof(t_beam));
		beamtemp->path = *path;
		(*beam)->next = beamtemp;
	}
}

void	add_vertex_to_path(t_path **path, int vertex)
{
	t_path *temppath;
	static	t_path *temp;

	if (!*path)
	{
		*path = malloc(sizeof(t_path));
		(*path)->next = NULL;
		(*path)->vertex = vertex;
		temp = *path;
	} else
	{
		while((*path)->next)
			(*path) = (*path)->next;
		temppath = malloc(sizeof(t_path));
		temppath->vertex = vertex;
		temppath->next = NULL;
		(*path)->next = temppath;
	}
	*path = temp;
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

void	print_path(t_path *path)
{
	while(path)
	{
		ft_putstr(" ");
		ft_putnbr(path->vertex);
		path = path->next;
	}
	ft_putstr("\n");
}

void	print_beam(t_beam *beam)
{
	int 	count;

	ft_putstr(__FUNCTION__);
	ft_putstr("\n");
	count = 1;
	while(beam)
	{
		ft_putstr(ft_itoa(count));
		ft_putstr(":");
		if (beam->path)
			print_path(beam->path);
		beam = beam->next;
		++count;
	}
	ft_putstr("\n");
}
