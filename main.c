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

void 	output_bits(void)
{
	short unsigned int bits;
	size_t	count;
	size_t	power;

	power = to_power(10, 2);
	printf("%lu \n", power);
	bits = 0;

	ft_putstr("bits: \n");
	while (bits < power)
	{
		count = 16;
		while (count--)
		{
			if (((bits >> count) & 1) == 1)
				//добавить путь к пучку
				ft_putchar('1');
			else
				ft_putchar('0');
			//перейти к следующему пути
		}
		//обработать пучек и добавить его к beams
		ft_putchar('\n');
		bits++;
	}
}

int		main(int ac, char **av)
{

	output_bits();
//	t_graph		g;
//	t_context	context;
//	t_beam		*beam;
//
//	init_bonuses(ac, av, &context);
//	context.free_beams = NULL;
//	context.free_beam = NULL;
//	context.debug = TRUE;
//	context.verify = TRUE;
//	beam = NULL;
//	initialize_graph(&g, &context, 0);
//	input(&g, &context);
//	initialize_bfs_search(&g);
//	beam = suurballe(&g, &context, context.start, context.end);
//	output(beam, &context);
//	clearing_structures(&g, &context, context.free_beams);
	return (0);
}
