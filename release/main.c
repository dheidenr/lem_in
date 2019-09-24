/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:09:03 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/21 13:09:06 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		main(int ac, char **av)
{
	t_graph		g;
	t_context	context;
	t_beam		*beam;
	t_beam		*dub_beam;

	init_bonuses(ac, av, &context);
	context.free_beams_one = NULL;
	context.free_beam_one = NULL;
	beam = NULL;
	initialize_graph(&g, &context, 0);
	input(&g, &context);
	initialize_bfs_search(&g);
	context.duplicate = FALSE;
	beam = suurballe(&g, &context, context.start, context.end);
	context.duplicate = TRUE;
	dub_beam = suurballe(&g, &context, context.start, context.end);
	if (!get_length_beam(beam))
		error();
	if (get_number_steps(&context, &beam)
		< get_number_steps(&context, &dub_beam))
		output(beam, &context);
	else
		output(dub_beam, &context);
	clearing_structures(&g, &context);
	return (0);
}
