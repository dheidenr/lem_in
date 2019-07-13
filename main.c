
#include "lem_in.h"
#include "exdlst.h"
#include "queue.h"



int main()
{
	graph g;
	int 	i;
	t_queue	*q;

	initialize_graph(&g, 0);

//	read_graph(&g, 0);
//	random_graph(&g, 0, 3998, 3999, 400000);
//	test_1_graph(&g, 0);
	test_too_path_graph(&g, 0);
	initialize_bfs_search(&g);
	initialize_dfs_search(&g);
	print_graph(&g);
//	bfs(&g, 1);
	dfs2(&g, 1);
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

	print_queue(shortest_bfs_path_search(&g, 1, 5), 0);

	return (0);
}
