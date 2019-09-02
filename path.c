
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

	tmp = (beam->isolate) ? NULL : beam;
	while(tmp && !tmp->isolate)
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
	tmp = beam;
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
		tmp = get_next_min_length_beam_and_isolate(tmp);
	}

}

void	step(t_beam *beam)
{
	t_path *path;

	path = beam->path;
	if (beam->ants > 0)
	{
		while (path->)
	}
}