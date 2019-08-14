
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

char 	is_exist_edge(graph *g, t_edgepoint *edp)
{
	t_edgenode *edgenode;

	edgenode = g->edges[edp->x];
	while(edgenode)
	{
		if (edgenode->y == edp->y)
			return (1);
		edgenode = edgenode->next;
	}
	return (0);
}


t_edgenode* 	get_edgenode(graph *g, t_edgepoint *edp)
{
	t_edgenode *edgenode;

	edgenode = g->edges[edp->x];
	while(edgenode)
	{
		if (edgenode->y == edp->y)
			return (edgenode);
		edgenode = edgenode->next;
	}
	return (NULL);
}

void	reverse_edge_and_weight(graph *g, t_edgepoint edp)
{
	t_edgepoint reversive_edge;
	t_edgenode	*edgenode;

	reversive_edge.x = edp.y;
	reversive_edge.y = edp.x;
	if (!is_exist_edge(g, &reversive_edge))
	{
		insert_edge_weight(g, &reversive_edge, TRUE, -get_weight_edge(g, &edp));
		edgenode = get_edgenode(g, &reversive_edge);
		edgenode->turn++;
	}
	else
	{
		edgenode = get_edgenode(g, &reversive_edge);
		edgenode->turn++;
		edgenode->weight *= -1;
	}
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

graph*	graphdub(graph* g)
{
	graph 			*graph_result;
	t_edgepoint ed;
	t_edgenode *edgenode;
	size_t				i;

	graph_result =  (graph *)malloc(sizeof(*g));
	i = 0;
	while(i <= g->nvertices)
	{
		edgenode = g->edges[i];
		ed.x = i;
		while(edgenode)
		{
			ed.y = edgenode->y;
			insert_edge_weight(graph_result, &ed, g->directed, edgenode->weight);
			edgenode = edgenode->next;
		}
		i++;
	}
	graph_result->directed = g->directed;
	graph_result->nvertices = g->nvertices;
	graph_result->nedges = g->nedges;
	i = 0;
	while (i <= MAXV)
	{
		graph_result->degree[i] = g->degree[i];
		i++;
	}
	return (graph_result);
}
