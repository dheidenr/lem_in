#include "lem_in.h"

#include "lem_in.h"

void	add_beam_to_beams(t_beams **beams, t_beam **beam, size_t number_steps)
{
	t_beams		*beams_temp;
	t_beams		*start_beams;

	if (!*beam)
		return ;
	if (!*beams)
	{
		*beams = (t_beams *) malloc(sizeof(t_beams));
		(*beams)->next = NULL;
		(*beams)->number_steps = number_steps;
	} else
	{
		start_beams = *beams;
		while ((*beams)->next)
			*beams = (*beams)->next;
		beams_temp = (t_beams *) malloc(sizeof(t_beams));
		beams_temp->beam = *beam;
		beams_temp->next = NULL;
		beams_temp->number_steps = number_steps;
		(*beams)->next = beams_temp;
		*beams = start_beams;
	}
}


//Написать функцию которая возвращает true_beam из beam который мы по порядку нашли.

//Этот beams содержит набор пучков из которых нужно выбрать оптимальный по количеству шагов необходимых для прохождения пучка
//Написать функцияю которая находит число шагов для прохождения конкретного пучка

//Написать функцию которая создает beams(со упорядоченным набором возрастающим путей) на основе подготовленного beam с найденными через суурбалле путями

t_beam	*get_beam_size(t_beam *beam, size_t	size)
{
	t_beam	*result;
	t_beam	*_beam;

	_beam = beam;
	result = NULL;
	if (!size)
		return (NULL);
	while(_beam && size)
	{
		add_path_to_beam(&result, &_beam->path, _beam->length);
		_beam = _beam->next;
		size--;
	}
	return (result);
}

//	(M+L)/k-1 (+1, если (M+L)%k != 0)
size_t	get_number_steps(t_context *context, t_beam **beam)
{
	size_t	global_length;
	size_t	result;
	size_t	paths;

	prepare_beam_ants(context->global_ants, *beam);
	global_length = get_length_paths(*beam);
	paths = get_length_beam(*beam);
	result = (context->global_ants + global_length)/paths;
	result += ((context->global_ants + global_length)%paths) ? 1 : 0;
	return (result);
}

t_beam	*get_min_number_steps_beam(t_beams	*beams)
{
	t_beams *tmp;
	t_beam	*result;
	size_t	min_steps;

	tmp = beams;
	if (!tmp)
		return (NULL);
	min_steps = tmp->number_steps;
	result = tmp->beam;
	while (tmp)
	{
		if (tmp->number_steps < min_steps)
		{
			min_steps = tmp->number_steps;
			result = tmp->beam;
		}
		tmp = tmp->next;
	}
	return (result);
}

t_beam	*find_optimal_beam(graph *g, t_context *context, t_beam *beam, t_edgepoint start_end)
{
	t_beam	*_beam;
	t_beam	*tmp_beam;
	t_beam	*start_beam;
	t_beams	*beams;
	size_t	size;

	size = 1;
	_beam = NULL;
	beams = NULL;
	tmp_beam = beam;
	while(size <= beam->length)
	{
		_beam = get_beam_size(beam, size);
		ft_putstr("_beam:\n");
		print_beam(_beam);
		tmp_beam = find_true_beam(g, context, _beam, start_end);
		if (tmp_beam)
			add_beam_to_beams(&beams, &_beam, get_number_steps(context, &beam));
		ft_putstr("tmp_beam:\n");
		print_beam(tmp_beam);
		size++;
	}
	tmp_beam = get_min_number_steps_beam(beams);
	return (tmp_beam);
}