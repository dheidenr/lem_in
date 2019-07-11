
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
	random_graph(&g, 0, 3998, 3999, 4000);
	initialize_search(&g);
	print_graph(&g);
	bfs(&g, 2);
	i = 0;
	ft_putstr("\n");
	while(++i <= MAXV)
	{
		ft_putstr(" ");
		ft_putnbr(g.parent[i]);
	}
	ft_putstr("\n");
	ft_putstr("\n");
	print_queue(shortest_path_search(&g, 2, 1818), 0);
	return (0);
}
