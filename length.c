
#include "lem_in.h"


t_beam	*get_next_min_length_beam_and_isolate(t_beam *beam)
{
	t_beam *tmp;
	t_beam	*result;
	size_t	min_len;

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

	tmp = beam;
	if (!beam)
		return (NULL);
	while(tmp && tmp->isolate)
		tmp = tmp->next;
	min_len = (tmp) ? tmp->length : 0;
	result = tmp;
	while (tmp)
	{
		if (tmp->length <= min_len)
		{
			min_len = tmp->length;
			result = tmp;
		}
		tmp = tmp->next;
	}
	return (result);
}

void	sort_by_lengths(t_beam *beam)
{
	t_beam	*tmp;
	t_beam	*swap_beam;

	swap_beam = beam;
	tmp = get_next_min_length_beam_and_isolate(beam);
	swap_paths(swap_beam, tmp);
	tmp = swap_beam;
	if (swap_beam)
		swap_beam = swap_beam->next;
	while (tmp)
	{
		tmp = get_next_min_length_beam_and_isolate(beam);
		swap_paths(swap_beam, tmp);
		tmp = swap_beam;
		if (swap_beam)
			swap_beam = swap_beam->next;
	}
}
