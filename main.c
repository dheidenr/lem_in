
#include "lem_in.h"
#include "exdlst.h"
#include "queue.h"



int main()
{
	graph g;
	t_context context;
	t_beam	*beam;
	size_t	count;
//	final_beam = suurballe();
//	output_ants(&g, final_beam);
	beam = NULL;
	initialize_graph(&g, &context, 0);
	input(&g, &context);

	count = 1;
	ft_putstr("names:\n");
	while(context.names[count])
	{
		ft_putstr(context.names[count]);
		ft_putchar('\n');
		count++;
	}

//	test_three_path_graph_suurballe_little(&g, &context, 0);
	ft_putstr("graph:\n");
	print_graph(&g);

	initialize_bfs_search(&g);
	initialize_dijkstra_search(&g, &context);
	context.start = 1;
	context.end = 6;
	context.global_ants = 3;
	beam = suurballe(&g, &context, context.start, context.end);

	print_beam(beam);

	output(beam, &context);

//	test();
	return (0);
}
