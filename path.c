
#include "lem_in.h"

/*
** 	ants_i = (M + L)/P - l_i
**
**
*/

t_beam	*get_next_min_length_beam_and_isolate(t_beam	*beam)
{
	t_beam *tmp;
	t_beam	*result;
	size_t	min_len;

//	tmp = (beam->isolate) ? NULL : beam;
	tmp = beam;
	if (!beam)
		return (NULL);
	while(tmp && tmp->isolate)
		tmp = tmp->next;

	min_len = (tmp) ? tmp->length : 0;
	result = tmp;
	while (tmp)
	{
		if (tmp->length < min_len && tmp->isolate == FALSE)
		{
			min_len = tmp->length;
			result = tmp;
		}
		tmp = tmp->next;
	}
	if (result)
		result->isolate = TRUE;
	return (result);
}

void	prepare_beam_ants(size_t global_ants, t_beam *beam)
{
	size_t	lost_ants;
	size_t	global_length;
	size_t	number_paths;
	float	cast;
	t_beam	*tmp;

	lost_ants = global_ants;
	//kostyl niz
	global_length = get_length_paths(beam);
	if (global_length == 1)
	{
		beam->ants = 1;
		if (beam->next)
			beam->next->ants = 0;
		return ;
	}
	//kostyl verh
	tmp = get_next_min_length_beam_and_isolate(beam);
	global_length = get_length_paths(beam);
	number_paths = get_length_beam(beam);

	while(tmp)
	{
		if (lost_ants > 0)
		{
			cast = ((float) global_ants + (float) global_length) /
				   number_paths - tmp->length;
			tmp->ants = (cast - (size_t) cast == 0) ?
						(global_ants + global_length) / number_paths
						- tmp->length :
						(global_ants + global_length) / number_paths
						- tmp->length + 1;
			lost_ants -= tmp->ants;
		}
		else
			tmp->ants = 0;
		tmp = get_next_min_length_beam_and_isolate(beam);
	}
}

void	print_ant_to_vertex(int ant, int vertex, t_context *context)
{
	ft_putstr(ft_strjoin("L", ft_itoa(ant)));
	ft_putstr(ft_strjoin("-", context->names[(size_t)vertex]));
//	ft_putchar(' ');
}

void	swap_two_ants_paths(t_path *p1, t_path *p2, t_context *context)
{
	int 	v;

	v = p1->ant;
	p1->ant = p2->ant;
	p2->ant = v;
	if (p1->ant != 0)
		print_ant_to_vertex(p1->ant, p2->vertex, context);
}

t_path	*get_path(t_path *path, size_t step)
{
	t_path	*p;

	if (step == 0 || (path && path->next && !path->next->next))
		return (path);
	if (!path)
		return (NULL);
	p = path;
//	step--;
	while(step > 0)
	{
		step--;
		p = p->next;
	}
	return (p);
}

void	offset_path(t_beam *beam, t_context *context)
{
	t_path	*p1;
	t_path	*p2;
	size_t	count;

	count = 0;
	if (get_path(beam->path, beam->length)->ant > 0)
		context->finish_ants++;
	while(count < beam->length)
	{
		p1 = get_path(beam->path, count);
		p2 = get_path(beam->path, count + 1);
		if (!p2)
			break ;
		swap_two_ants_paths(p1, p2, context);
		count++;
	}
	beam->path->next->ant = 0;
}

void	add_ant_one_path(t_beam *beam, int ant, t_context *context)
{

	beam->path->ant = ant;
	print_ant_to_vertex(ant, beam->path->next->vertex, context);
	beam->ants--;
}
void	step_on_the_path(t_beam *beam, int ant, t_context *context)
{
//	t_path	*tmp;
//	t_path	*prev;
//	size_t	len;
//
	if (beam->ants > 0)
		add_ant_one_path(beam, ant, context);
	offset_path(beam, context);

//	len = 1;
//			tmp = beam->path;
//			if (tmp->ant != 0)
//				while (len > 0)
//				{
//					len = 0;
//					tmp = beam->path;
//					prev = NULL;
//					while (tmp->ant > 0)
//					{
//						prev = tmp;
//						tmp = tmp->next;
//						len++;
//					}
//					if (tmp->next)
//					{
//						if (prev)
//							tmp->ant = prev->ant;
//						if (prev)
//							prev->ant = 0;
//						ft_putstr(ft_strjoin("L", ft_itoa((int) ant)));
//						ft_putstr(ft_strjoin("-",
//						context->names[(size_t)(int)tmp->next->vertex]));
//					} else
//					{
//						ft_putstr(ft_strjoin("L", ft_itoa((int) ant)));
//						ft_putstr(ft_strjoin("-",
//						context->names[(size_t)(int)tmp->vertex]));
//						context->finish_ants += 1;
//					}
//
//				}
//			else
//			{
//				tmp->ant = ant;
//				ft_putstr(ft_strjoin("L", ft_itoa((int) ant)));
//				ft_putstr(ft_strjoin("-",
//				context->names[(size_t)(int) tmp->next->vertex]));
//			}
//			ft_putchar(' ');
//			beam->ants--;
}

void	ants_go_the_paths(t_beam *beam, t_context *context)
{
	t_path	*path;
	t_beam	*tmp_beam;
	size_t	ant;
	size_t	stop;

	ant = 0;
	stop = 0;
	context->finish_ants = 0;
	tmp_beam = beam;
	if (beam)
		path = beam->path;
	else
		return ;
	while (context->finish_ants < context->global_ants)
	{
		if (path && beam->ants)
			step_on_the_path(beam,ant = (beam->ants > 0 ) ? ant + 1 : ant, context);
		beam = beam->next;
		if (beam)
		{
			path = beam->path;
			ft_putchar(' ');
		}
		else
		{
			beam = tmp_beam;
			path = beam->path;
			ft_putchar('\n');
		}

		stop++;
//		if (stop == 9)
//			exit(0);
	}
}
