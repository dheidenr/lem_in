
#include "lem_in.h"

/*
** 	ants_i = (M + L)/P - l_i
*/

void	fill_ants(float *lost_ants, t_beam *beam)
{
	if (beam->ants >= *lost_ants || !beam->next)
	{
		beam->ants = *lost_ants;
		*lost_ants = 0;
	}
	else if (*lost_ants)
		*lost_ants -= beam->ants;
	else
		beam->ants = 0;
}

int 	is_one_length(t_beam *beam, size_t global_length, size_t global_ants)
{
	if (global_length == 1)
	{
		beam->ants = global_ants;
		if (beam->next)
			beam->next->ants = 0;
		return (1);
	}
	return (0);
}

void	prepare_beam_ants(size_t global_ants, t_beam *beam)
{
	float	lost_ants;
	size_t	global_length;
	size_t	number_paths;
	t_beam	*tmp;

	lost_ants = global_ants;
	global_length = get_length_paths(beam);
	if (is_one_length(beam, global_length, global_ants))
		return ;
	tmp = beam;
	number_paths = get_length_beam(beam);
	while(tmp)
	{
		if (lost_ants > 0)
		{
			tmp->ants = (global_ants + global_length + number_paths)
					/ (number_paths) - (tmp->length);
			tmp->ants -= (number_paths == 2)? 1:0;
			fill_ants(&lost_ants, tmp);
		}
		else
			tmp->ants = 0;
		tmp = tmp->next;
	}
}
