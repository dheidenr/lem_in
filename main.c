
#include "lem_in.h"
#include "exdlst.h"
#include "queue.h"

int main()
{
	graph g;
	int 	i;
	t_queue	*q;

	initialize_graph(&g, 0);

	read_graph(&g, 0);
//	random_graph(&g, 0, 15, 16, 27);
	initialize_search(&g);
	print_graph(&g);
	bfs(&g, 1);
	i = 0;
	ft_putstr("\n");
	while(++i <= MAXV)
	{
		ft_putstr(" ");
		ft_putnbr(g.parent[i]);
	}

	return (0);
}
