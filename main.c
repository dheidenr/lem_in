
#include "lem_in.h"
#include "exdlst.h"
#include "queue.h"



int main()
{
	graph g;
	t_context context;
	graph *dubg;
	int 	i;
	t_queue	*q;
	t_edgepoint edp;

	initialize_graph(&g, 0);

//	read_graph(&g, 0);
//	random_graph(&g, 0, 3998, 3999, 400000);
//	test_1_graph(&g, 0);
//	test_too_path_graph(&g, 0);
//	test_24_4_graph_bellman_ford(&g, 1);
	test_too_path_graph_suurballe(&g, 0);
	initialize_bfs_search(&g);
	initialize_dfs_search(&g, &context);
	initialize_dijkstra_search(&g, &context);
	print_graph(&g);
//	suurballe(&g, 1, 6);

//	bfs(&g, 1);
//	dfs2(&g, 1);
	dijkstra(&g, 1);
//	if (!bellman_ford(&g, 1))
//		ft_putstr("\nERROR_CYRCLE_NEGATIVE\n");
	i = 0;
	ft_putstr("\nparent\n");
	while(++i <= MAXV)
	{
		ft_putstr(" ");
		ft_putnbr(g.parent[i]);
	}
	ft_putstr("\ncolor\n");
	i = 0;
	while(++i <= MAXV)
	{
		ft_putstr(" ");
		ft_putnbr(g.color[i]);
	}
	ft_putstr("\nentry time\n");
	i = 0;
	while(++i <= MAXV)
	{
		ft_putstr(" ");
		ft_putnbr(context.entry_time[i]);
	}
	ft_putstr("\nexit_time\n");
	i = 0;
	while(++i <= MAXV)
	{
		ft_putstr(" ");
		ft_putnbr(context.exit_time[i]);
	}
	ft_putstr("\n");
	ft_putstr("\nshort_paths\n");
	i = 0;
	while(++i <= MAXV)
	{
		ft_putstr(" ");
		ft_putnbr(context.short_paths[i]);
	}
	ft_putstr("\n");
//	print_queue(shortest_bfs_path_search(&g, 1, 5), 0);
	init_queue(&q);
	print_queue(qfind_path(1, 6, g.parent, &q), 0);

	//test funcion of suurballe
	dubg = graphdub(&g);
	edp.x = 4;
	edp.y = 6;
	remove_edge(dubg, edp, TRUE);

	void			reverse_edge_and_weight(graph *g, t_edgepoint edp);
//	edp.x = 5;
//	edp.y = 6;
//
//	remove_edge(dubg, edp, FALSE);

	initialize_dijkstra_search(dubg, &context);
	dijkstra(dubg, 1);
	print_graph(dubg);
	init_queue(&q);
	print_queue(qfind_path(1, 6, dubg->parent, &q), 0);
	return (0);
}
