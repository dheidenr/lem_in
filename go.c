
#include "lem_in.h"

void	add_ant_one_path(t_beam *beam, int ant)
{
	beam->path->ant = ant;
	beam->ants--;
}

void	step_on_the_path(t_beam *beam, int ant, t_context *context)
{
	if (beam->ants > 0)
		add_ant_one_path(beam, ant);
	offset_path(beam, context);
}

void	print_debug(int debug_len, t_context *context, t_beam *tmp_beam)
{
	if (debug_len)
	{
		ft_putstr("real number steps:");
		putstr_free(ft_itoa(debug_len));
		ft_putchar('\n');
		ft_putstr("virtual number steps:");
		putstr_free(ft_itoa((int)get_number_steps(context, &tmp_beam)));
	}
}

void	step(t_support_beam *sup, t_context *context, int *debug_len)
{
	if (sup->beam)
		sup->path = sup->beam->path;
	else
	{
		sup->beam = sup->tmp_beam;
		sup->path = sup->beam->path;
		context->flag = 0;
		if (context->finish_ants < context->global_ants)
		{
			ft_putchar('\n');
			if (context->verify)
				(*debug_len)++;
		}
	}
}

void	ants_go_the_paths(t_beam *beam, t_context *context)
{
	t_support_beam	sup;
	size_t			ant;
	size_t			stop;
	int				debug_len;

	ant = 0;
	stop = 0;
	debug_len = 0;
	context->finish_ants = 0;
	sup.tmp_beam = beam;
	if (!beam)
		return ;
	sup.path = beam->path;
	sup.beam = beam;
	while (context->finish_ants < context->global_ants)
	{
		if (sup.path)
			step_on_the_path(sup.beam,
					ant = (sup.beam->ants > 0) ? ant + 1 : ant, context);
		sup.beam = sup.beam->next;
		step(&sup, context, &debug_len);
		stop++;
	}
	print_debug(debug_len, context, sup.tmp_beam);
}
