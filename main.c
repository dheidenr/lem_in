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

t_beam 	*output_bits(t_beam *beam, t_graph *g, t_context *context)
{
	short unsigned int bits;
	size_t	count;
	size_t	power;
	t_beam	*tmp;
	t_beam	*result_beam;
	t_beams	*beams;
	t_beams *p_beams;
	size_t	len;
	beams = NULL;

	power = to_power(get_length_beam(beam), 2);
	bits = 0;
	result_beam = NULL;
	tmp = beam;
//	printf("power:%lu\n", power);
////	if (power > TWO_POWER_14)
////		return (NULL);
//	ft_putstr("bits: \n");
	while (bits < power)
	{
		tmp = beam;
		len = get_length_beam(beam);
		count = 0;
		while (count < len)
		{
			if (((bits >> count) & 1) == 1)
			{
				//добавить путь к пучку
				//
				add_path_to_beam(&result_beam, &(tmp->path), tmp->length);
//				ft_putchar('1');
			}
//			else
//				ft_putchar('0');
			//перейти к следующему пути
			if (tmp)
				tmp = tmp->next;
			count++;
		}
		//обработать пучек и добавить его к beams
//		result_beam = find_true_beam(g, result_beam, p);
//		sort_by_lengths(result_beam);
//		add_beam_to_beams(&beams, &result_beam, get_number_steps(context, &result_beam));
		if (result_beam)
			find_and_add_beam_to_beams(&beams, &result_beam, g, context);
		result_beam = NULL;
//		ft_putchar('\n');
		bits++;
	}
	p_beams = beams;

//	ft_putstr("beams");
//	while(p_beams)
//	{
//		print_beam(p_beams->beam);
//		p_beams = p_beams->next;
//	}
	context->free_beams = beams;
	tmp = get_min_number_steps_beam(beams);
	return(tmp);
}

int		main(int ac, char **av)
{

//	output_bits();
	t_graph		g;
	t_context	context;
	t_beam		*beam;
	t_beam		*dub_beam;

	init_bonuses(ac, av, &context);
	context.free_beams = NULL;
	context.free_beam = NULL;
//	context.debug = TRUE;
//	context.verify = TRUE;
	beam = NULL;
	initialize_graph(&g, &context, 0);
	input(&g, &context);
	initialize_bfs_search(&g);


//	print_graph(&g);

//
//	t_edgepoint start_end;
//	start_end.x = context.start;
//	start_end.y = context.end;
//	print_shortest_path(&g, start_end);

	context.duplicate = FALSE;
	beam = suurballe(&g, &context, context.start, context.end);
	context.duplicate = TRUE;
	dub_beam = suurballe(&g, &context, context.start, context.end);
	if (get_number_steps(&context, &beam) < get_number_steps(&context, &dub_beam))
		output(beam, &context);
	else
		output(dub_beam, &context);
	clearing_structures(&g, &context, context.free_beams);
	return (0);
}
