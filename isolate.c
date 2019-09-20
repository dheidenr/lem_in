
#include "lem_in.h"


void	correct_edge(t_support_edge *sup_edge, t_graph *g)
{
	if (sup_edge->edge)
	{
		sup_edge->reverse_edge = get_edgenode(g,
											  reverse_edgepoint(&sup_edge->edp, sup_edge->rev_edp));
		if (sup_edge->edge->turn > 0 &&
			sup_edge->reverse_edge->turn > 0)
		{
			sup_edge->edge->isolate = TRUE;
			sup_edge->reverse_edge->isolate = TRUE;
		}
		if (sup_edge->edge->turn > 1)
			sup_edge->edge->isolate = TRUE;
		if (sup_edge->reverse_edge->turn > 1)
			sup_edge->reverse_edge->isolate = TRUE;
	}
}

void	no_isolate_edges(t_beam *beam, t_support_beam *sup_beam,
						 t_support_edge *sup_edge, t_graph *g)
{
	beam = sup_beam->tmp_beam;
	while (beam)
	{
		sup_beam->path = beam->path;
		sup_edge->edp.x =sup_beam-> path->vertex;
		sup_beam->path = sup_beam->path->next;
		while (sup_beam->path)
		{
			sup_edge->edp.y = sup_beam->path->vertex;
			sup_edge->edge = get_edgenode(g, &sup_edge->edp);
			correct_edge(sup_edge, g);
			sup_beam->path = sup_beam->path->next;
			sup_edge->edp.x = sup_edge->edp.y;
		}
		beam = beam->next;
	}
}

void	cycle_no_isolate_all_edges_of_beam(t_support_edge *sup_edge,
										   t_support_beam *sup_beam, t_graph *g)
{
	while (sup_beam->path)
	{
		sup_edge->edp.y = sup_beam->path->vertex;
		sup_edge->edge = get_edgenode(g, &sup_edge->edp);
		if (sup_edge->edge)
		{
			sup_edge->edge->turn++;
			sup_edge->edge->isolate = FALSE;
		}
		sup_beam->path = sup_beam->path->next;
		sup_edge->edp.x = sup_edge->edp.y;
	}
}

void 	no_isolate_all_edges_of_beam(t_graph *g, t_beam *beam)
{
	t_support_beam	sup_beam;
	t_support_edge	sup_edge;

	sup_beam.tmp_beam = beam;
	sup_edge.rev_edp = (t_edgepoint *)ft_memalloc(sizeof(t_edgepoint));
	while (beam)
	{
		sup_beam.path = beam->path;
		sup_edge.edp.x = sup_beam.path->vertex;
		sup_beam.path = sup_beam.path->next;
		cycle_no_isolate_all_edges_of_beam(&sup_edge, &sup_beam, g);
		beam = beam->next;
	}
	no_isolate_edges(beam, &sup_beam, &sup_edge, g);
	free(sup_edge.rev_edp);
	sup_edge.rev_edp = NULL;
}
