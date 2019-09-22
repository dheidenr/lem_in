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

size_t	to_power(size_t degree, size_t base)
{
	size_t	number;

	if (degree <= 0)
		return (1);
	number = base;
	while(--degree)
		number = number * base;
	return (number);
}

void	find_and_add_beam_to_beams(t_beams **beams, t_beam **result_beam, t_graph *g, t_context *context)
{
	t_edgepoint point;

	point.x = context->start;
	point.y = context->end;
	*result_beam = find_true_beam(g, *result_beam, point);
	sort_by_lengths(*result_beam);
	add_beam_to_beams(beams, result_beam, get_number_steps(context, result_beam));
}

void 	output_bits(t_beam *beam, t_graph *g, t_context *context)
{
	short unsigned int bits;
	size_t	count;
	size_t	power;
	t_beam	*tmp;
	t_beam	*result_beam;
	t_beams	*beams;

	beams = NULL;

	power = to_power(get_length_beam(beam), 2);
	bits = 0;
	result_beam = NULL;
	tmp = beam;
	printf("power:%lu\n", power);
	if (power > TWO_POWER_14)
		return ;
	ft_putstr("bits: \n");
	while (bits < power)
	{
		count = get_length_beam(beam);
		while (count--)
		{
			if (((bits >> count) & 1) == 1)
			{
				//добавить путь к пучку
				//
				add_path_to_beam(&result_beam, &(tmp->path), tmp->length);
				ft_putchar('1');
			}
			else
				ft_putchar('0');
			//перейти к следующему пути
			if (tmp)
				tmp = tmp->next;

		}
		//обработать пучек и добавить его к beams
//		result_beam = find_true_beam(g, result_beam, p);
//		sort_by_lengths(result_beam);
//		add_beam_to_beams(&beams, &result_beam, get_number_steps(context, &result_beam));
		if (result_beam)
			find_and_add_beam_to_beams(&beams, &result_beam, g, context);
		result_beam = NULL;
		ft_putchar('\n');
		bits++;
	}
}

int		main(int ac, char **av)
{

//	output_bits();
	t_graph		g;
	t_context	context;
	t_beam		*beam;

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
