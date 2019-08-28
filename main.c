
#include "lem_in.h"
#include "exdlst.h"
#include "queue.h"



int main()
{
	graph g;
	t_context context;
	char **vertex;


//	final_beam = suurballe();
//	output_ants(&g, final_beam);

	ft_putstr("before input\n");
	print_graph(&g);
	input(&g, &context);
	ft_putstr("after input\n");
	print_graph(&g);

//	test();
	return (0);
}
