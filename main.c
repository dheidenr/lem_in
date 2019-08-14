
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
	t_path	*path;
	t_beam	*beam;

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
		ft_putnbr(g.parents[i]);
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
	print_queue(qfind_path(1, 6, g.parents, &q), 0);

	//test function of suurballe
	path = NULL;
	beam = NULL;
//	find_path(1, 6, g.parents, &path);
//	add_path_to_beam(&beam, &path);

	i = 0;
	ft_putstr("\nparent g\n");
	while(++i <= MAXV)
	{
		ft_putstr(" ");
		ft_putnbr(g.parents[i]);
	}

	dubg = graphdub(&g);

//	edp.x = 4;
//	edp.y = 6;
////	reverse_edge_and_weight(&g, edp);
//	edp.x = 6;
//	edp.y = 4;
//	remove_edge(dubg, edp, TRUE);
//	reverse_edge_and_weight(&g, edp);
//	edp.x = 4;
//	edp.y = 6;
//	printf("\n%d:weight\n", get_weight_edge(&g, &edp));



//	edp.x = 6;
//	edp.y = 4;
//	reverse_edge_and_weight(dubg, edp);
//
//	edp.x = 4;
//	edp.y = 6;
//	printf("get_weight_reverse:%d|\n", get_weight_edge(dubg, &edp));
//	edp.x = 6;
//	edp.y = 4;
//
//	remove_edge(dubg, edp, FALSE);

//	initialize_dijkstra_search(dubg, &context);
//	dijkstra(dubg, 1);

//	i = 0;
//	ft_putstr("\nparent dubg\n");
//	while(++i <= MAXV)
//	{
//		ft_putstr(" ");
//		ft_putnbr(dubg->parents[i]);
//	}

//	path = NULL;
//	path = find_path(1, 6, dubg->parents, &path);

//	add_path_to_beam(&beam, &path);

	beam = suurballe(dubg, &context, 1, 6);
//	i = 0;
//	ft_putstr("\nparent main dubg\n");
//	while(++i <= MAXV)
//	{
//		ft_putstr(" ");
//		ft_putnbr(dubg->parents[i]);
//	}

	print_beam(beam);
	print_graph(dubg);

//hack array (int[128])*(char*)parents
//	init_queue(&q);
//	print_queue(qfind_path(1, 6, dubg->parents, &q), 0);
	return (0);
}
