
#include "lem_in.h"

void	extra_situation(t_beam **beam, t_beam **true_beam, t_path **path)
{
	if (!*true_beam && *beam)
	{
		*true_beam = get_min_length_beam(*beam);
		*path = (*beam)->path;
		(*true_beam)->path = NULL;
		*true_beam = NULL;
		add_path_to_beam(true_beam, path, get_length_path(*path));
	}
}

void	clean_beam(t_beam **beam, t_beam **fake_beam)
{
	*fake_beam = *beam;
	while (*beam)
	{
		*beam = (*beam)->next;
		free(*fake_beam);
		*fake_beam = NULL;
		*fake_beam = *beam;
	}
}

void	init_find_true_beam(t_support_edge *se, t_support_beam *sb, t_graph *g, t_edgepoint *start_end)
{
	turn_to_zero_all_edges(g);
	isolate_all_edges(g);
	no_isolate_all_edges_of_beam(g, sb->beam);
	sb->path = NULL;
	sb->true_beam = NULL;
	se->edge = g->edges[start_end->x];
	isolate_edgenode(se->edge, TRUE);
	se->edp.x = start_end->x;
}

t_beam *find_true_beam(t_graph *g, t_beam *fake_beam, t_edgepoint start_end)
{
	t_support_edge se;
	t_support_beam sb;

	sb.beam = fake_beam;
	init_find_true_beam(&se, &sb, g, &start_end);
	while(fake_beam)
	{
		se.edp.y = fake_beam->path->next->vertex;
		se.tmp_edge = get_edgenode(g, &se.edp);
		se.tmp_edge->isolate = FALSE;
		initialize_bfs_search(g);
		bfs(g, start_end.x);
		sb.path = NULL;
		sb.path = find_path(start_end.x, start_end.y, g->parents, &sb.path);
		if (!is_elements_of_path_in_beam(sb.true_beam, sb.path))
			add_path_to_beam(&sb.true_beam, &sb.path, get_length_path(sb.path));
		else
			clear_path(sb.path);
		se.tmp_edge->isolate = TRUE;
		fake_beam = fake_beam->next;
	}
	isolate_edgenode(se.edge, FALSE);
	extra_situation(&sb.beam, &sb.true_beam, &sb.path);
	clean_beam(&sb.beam, &fake_beam);
	return (sb.true_beam);
}
