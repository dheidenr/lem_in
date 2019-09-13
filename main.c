
#include "lem_in.h"
#include "exdlst.h"
#include "aqueue.h"

int main(int ac, char **av)
{
	graph g;
	t_context context;
	t_beam	*beam;
//	size_t	count;
//	final_beam = suurballe();
//	output_ants(&g, final_beam);
	if (ac == 2 && av[1] && av[1][0] && av[1][0] == '-' && av[1][1] && av[1][1] == 'd' && av[1][2] == '\0')
		context.debug = TRUE;
	else
		context.debug = FALSE;

	context.free_beams = NULL;
	context.free_beam = NULL;
	beam = NULL;
	initialize_graph(&g, &context, 0);
	input(&g, &context);
//	count = 1;
//	ft_putstr("names:\n");
//	while(context.names[count])
//	{
//		ft_putstr(context.names[count]);
//		ft_putchar('\n');
//		count++;
//	}
//	test_three_path_graph_suurballe_little(&g, &context, 0);
//	ft_putstr("graph:\n");
//	print_graph(&g);

	initialize_bfs_search(&g);
	initialize_dijkstra_search(&g, &context);
//	context.start = 2;
//	context.end = 3;
//	context.global_ants = 3;
	beam = suurballe(&g, &context, context.start, context.end);
	output(beam, &context);

//	test();

	clearing_structures(&g, &context, context.free_beams);
//	t_aqueue *q;
//	size_t		count;
//	int 		number;
//	int 		xz;
//
//	count = 666;
//	xz = 7;
//	q = NULL;
//	init_aqueue(&q);
//
//	while (count <= 7777)
//	{
//		enaqueue(q, count);
//		count++;
//	}
//
//	while (!is_empty_aqueue(q))
//	{
//		number = deaqueue(q);
//		printf("len:%lu|cursor:%lu|end:%lu|nbr:%d|\n", q->length, q->cursor, q->end, number);
//	}
//
//	count = 0;
//	while (count <= 7)
//	{
//		enaqueue(q, count);
//		count++;
//	}
//
//	print_aqueue(q);

	return (0);
}
