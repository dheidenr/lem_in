

#include "lem_in.h"

size_t	find_number_steps(t_beam *beam)
{

	return (0);
}

void	add_beam_to_beams(t_beams **beams, t_path **path, size_t number_steps)
{
	t_beams		*beamtemp;
	t_beams		*start_beam;

	if (!*path)
		return ;
	if (!*beams)
	{
		*beams = (t_beams *) malloc(sizeof(t_beams));
		(*beams)->next = NULL;
		(*beams)->number_steps = number_steps;
	} else
	{
		start_beam = *beams;
		while ((*beams)->next)
			*beams = (*beams)->next;
		beamtemp = (t_beams *) malloc(sizeof(t_beams));
		beamtemp->next = NULL;
		beamtemp->number_steps = number_steps;
		(*beams)->next = beamtemp;
		*beams = start_beam;
	}
}

//Написать функция которая находит количество шагов
//Написать функцию которая создает beams(со всевозможными вариантами пучков) на основе подготовленного beam с найденными через суурбалле путями
//Этот beams содержит набор пучков из которых нужно выбрать оптимальный по количеству шагов необходимых для прохождения пучка


//Написать функцияю которая находит число шагов для прохождения конкретного пучка

