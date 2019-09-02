
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

void	step_on_the_path(t_beam *beam, size_t ant)
{
	t_path	*tmp;
	t_path	*prev;
	size_t	len;

	len = 1;
		if (beam->ants > 0)
		{
			tmp = beam->path;
			if (tmp->ant != 0)
				while (len > 0)
				{
					len = 0;
					tmp = beam->path;
					prev = NULL;
					while (tmp->ant > 0)
					{
						prev = tmp;
						tmp = tmp->next;
						len++;
					}
					if (tmp->next)
					{
						if (prev)
							tmp->ant = prev->ant;
						if (prev)
							prev->ant = 0;
						ft_putstr(ft_strjoin(" L", ft_itoa((int) ant)));
						ft_putstr(ft_strjoin("-",
											 ft_itoa((int) tmp->next->vertex)));
					} else
					{
						ft_putstr(ft_strjoin(" L", ft_itoa((int) ant)));
						ft_putstr(ft_strjoin("-", ft_itoa((int) tmp->vertex)));
					}

				}
			else
				tmp->ant = ant;
			ft_putchar('\n');
			beam->ants--;
		}
//			if (tmp && tmp->next)
//			{
//				tmp->next->ant = ant;
//				tmp->ant = 0;
//				ft_putstr(ft_strjoin("L", ft_itoa((int)ant)));
//				ft_putstr(ft_strjoin("-", ft_itoa((int)tmp->next->vertex)));
//			}

}

void	ants_go_the_paths(t_beam *beam)
{
	t_path	*path;
	t_beam	*tmp_beam;
	size_t	ant;

	ant = 1;
	tmp_beam = beam;
	if (beam)
		path = beam->path;
	else
		return ;
	while (beam && beam->ants > 0)
	{
		if (path)
			step_on_the_path(beam, ant++);
		beam = beam->next;
		if (beam)
			path = beam->path;
		else
		{
			beam = tmp_beam;
			path = beam->path;
		}
	}
}
