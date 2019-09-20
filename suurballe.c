
#include "lem_in.h"
#include "libft.h"
#include "exdlst.h"

t_edgepoint	*reverse_edgepoint(t_edgepoint *edgepoint, t_edgepoint *reverse_edge)
{
	reverse_edge->x = edgepoint->y;
	reverse_edge->y = edgepoint->x;
	return (reverse_edge);
}

void	rebfs_and_reverse_and_add_path(t_graph *g, t_edgepoint start_end,
									   t_support_beam *sb, t_graph *gdub)
{
	size_t	i;
	int 	start;
	int 	end;

	start = start_end.x;
	end = start_end.y;
	i = 1;
	while (i <= g->degree[start])
	{
		initialize_bfs_search(gdub);
		bfs(gdub, start);
		sb->path = NULL;
		sb->path = find_path(start, end, gdub->parents, &sb->path);

		if (!sb->path)
			break ;
		reverse_path(gdub, sb->path);
		remove_fake_vertexes(gdub, sb->context, &sb->path);
		add_path_to_beam(&sb->beam, &sb->path, get_length_path(sb->path));
		i++;
	}
}

void	find_optimal_and_print_debug(t_graph *g, t_edgepoint start_end,
									 t_support_beam *sb)
{
	if (get_length_beam(sb->beam) > 1)
	{
		if (sb->context->debug)
		{
			ft_putstr("after suurballe:\n");
			print_beam(sb->beam);
			ft_putchar('\n');
		}
		sb->context->free_beam = sb->beam;
		sb->beam = find_optimal_beam(g, sb->context, sb->beam, start_end);
	} else
		sb->context->free_beam = sb->beam;
}

t_beam	*suurballe(t_graph *g, t_context *context, int start, int end)
{
	t_edgepoint		start_end;
	t_support_beam	sb;
	t_graph			*gdub;

	start_end.x = start;
	start_end.y = end;
	gdub = graphdub(g);
	duplicate_all_vertexes_graph(gdub, context, start, end);
	initialize_bfs_search(gdub);
	bfs(gdub, start);
	sb.path = NULL;
	sb.beam = NULL;
	sb.path = find_path(start, end, gdub->parents, &sb.path);
	reverse_path(gdub, sb.path);
	remove_fake_vertexes(gdub, context, &sb.path);
	add_path_to_beam(&sb.beam, &sb.path, get_length_path(sb.path));
	sb.context = context;
	rebfs_and_reverse_and_add_path(g, start_end, &sb, gdub);
	find_optimal_and_print_debug(g, start_end, &sb);
	clear_graph(gdub);
	return (sb.beam);
}
