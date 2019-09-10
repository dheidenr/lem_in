
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

t_beam	*get_min_length_beam(t_beam	*beam)
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
		if (tmp->length < min_len)
		{
			min_len = tmp->length;
			result = tmp;
		}
		tmp = tmp->next;
	}
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
		beam->ants = global_ants;
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
			if (tmp->ants >= lost_ants)
			{
				tmp->ants = lost_ants;
				lost_ants = 0;
			}
			else if (lost_ants)
				lost_ants -= tmp->ants;
			else
				tmp->ants = 0;
		}
		else
			tmp->ants = 0;
		tmp = get_next_min_length_beam_and_isolate(beam);
	}
}

void	print_ant_to_vertex(int ant, int vertex, t_context *context)
{
	putstr_free(strjoin_free("L", ft_itoa(ant), 2));
	putstr_free(ft_strjoin("-", context->names[(size_t)vertex]));
//	ft_putchar(' ');
}

void	move_ant(t_path *src, t_path *dst, t_context *context)//, char end_space)
{
//	int 	ant;
//
//	ant = src->ant;
//	src->ant = dst->ant;
//	dst->ant = ant;
	dst->ant = src->ant;
	if (src->ant != 0)
		print_ant_to_vertex(src->ant, dst->vertex, context);
//	if (src->ant != 0 && dst->ant != 0 && end_space)
//		ft_putchar(' ');
}

t_path	*get_path(t_path *path, size_t step)
{
	t_path	*p;

	if (step == 0)// || (path && path->next && !path->next->next))
		return (path);
	if (!path)
		return (NULL);
	p = path;
//	step--;
	while(p && step > 0)
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
//	char 	flag;


	count = 0;
	if (get_path(beam->path, beam->length)->ant > 0)
		context->finish_ants++;
	while(count < beam->length)
	{
		p1 = get_path(beam->path, /*(beam->length == 1) ? 2 :*/ beam->length - count - 1);
		p2 = get_path(beam->path, /*(beam->length == 1) ? 2 :*/ beam->length - count);
		if (!p2)
			break ;
//		if (p1->ant != 0)
		if (context->flag && p1->ant != 0)
			ft_putchar(' ');
		if (p1->ant != 0)
			context->flag = 1;
		move_ant(p1, p2, context);//, (0) ?  END_SPACE : NOT_END_SPACE);
		count++;

	}
	beam->path->ant = 0;
}

void	add_ant_one_path(t_beam *beam, int ant, t_context *context)
{

	beam->path->ant = ant;
//	print_ant_to_vertex(ant, beam->path->next->vertex, context);
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
	int	debug_len;

	ant = 0;
	stop = 0;
	debug_len = 0;
	context->finish_ants = 0;
	tmp_beam = beam;
	if (beam)
		path = beam->path;
	else
		return ;
	while (context->finish_ants < context->global_ants)
	{
		if (path)
			step_on_the_path(beam,ant = (beam->ants > 0 )  ? ant + 1 : ant,
																	context);
		beam = beam->next;
		if (beam)
			path = beam->path;
		else
		{
			beam = tmp_beam;
			path = beam->path;
			context->flag = 0;
			if (context->finish_ants < context->global_ants)
			{
				ft_putchar('\n');
				if (context->debug)
					debug_len++;
			}


		}
		stop++;
//		if (stop == 9)
//			exit(0);
	}
	if (debug_len)
		putstr_free(ft_itoa(debug_len));
}
