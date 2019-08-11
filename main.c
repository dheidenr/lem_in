
#include "lem_in.h"
#include "exdlst.h"
#include "queue.h"



int main()
{
	graph g;
	graph *dubg;
	int 	i;
	t_queue	*q;

	initialize_graph(&g, 0);

//	read_graph(&g, 0);
//	random_graph(&g, 0, 3998, 3999, 400000);
//	test_1_graph(&g, 0);
//	test_too_path_graph(&g, 0);
//	test_24_4_graph_bellman_ford(&g, 1);
	test_too_path_graph_suurballe(&g, 1);
	initialize_bfs_search(&g);
	initialize_dfs_search(&g);
	initialize_dijkstra_search(&g);
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
		ft_putnbr(g.entry_time[i]);
	}
	ft_putstr("\nexit_time\n");
	i = 0;
	while(++i <= MAXV)
	{
		ft_putstr(" ");
		ft_putnbr(g.exit_time[i]);
	}
	ft_putstr("\n");
	ft_putstr("\nshort_paths\n");
	i = 0;
	while(++i <= MAXV)
	{
		ft_putstr(" ");
		ft_putnbr(g.short_paths[i]);
	}
	ft_putstr("\n");
//	print_queue(shortest_bfs_path_search(&g, 1, 5), 0);
	init_queue(&q);
	print_queue(qfind_path(1, 6, g.parent, &q), 0);

	//test funcion of suurballe
	dubg = graphdub(&g);

	initialize_dijkstra_search(dubg);
	dijkstra(dubg, 1);
	print_graph(dubg);
	init_queue(&q);
	print_queue(qfind_path(1, 6, g.parent, &q), 0);
	return (0);
}
