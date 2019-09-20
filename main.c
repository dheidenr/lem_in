
#include "lem_in.h"
#include "exdlst.h"

void	init_bonuses(int ac, char **av, t_context *context)
{
	if (ac == 2 && av[1] && av[1][0] && av[1][0] == '-'
		&& av[1][1] && av[1][1] == 'v' && av[1][2] == '\0')
		context->verify = TRUE;
	else
		context->verify = FALSE;
	if (ac == 2 && av[1] && av[1][0] && av[1][0] == '-'
	&& av[1][1] && av[1][1] == 'd' && av[1][2] == '\0')
		context->debug = TRUE;
	else
		context->debug = FALSE;
}

int main(int ac, char **av)
{
	t_graph g;
	t_context context;
	t_beam	*beam;

	init_bonuses(ac, av, &context);
	context.free_beams = NULL;
	context.free_beam = NULL;
	context.debug = TRUE;
	context.verify = TRUE;
	beam = NULL;
	initialize_graph(&g, &context, 0);
	input(&g, &context);
	initialize_bfs_search(&g);
	beam = suurballe(&g, &context, context.start, context.end);
	output(beam, &context);
	clearing_structures(&g, &context, context.free_beams);
	return (0);
}
