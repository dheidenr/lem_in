
#include "lem_in.h"


void	clear_path(t_path *path)
{
	t_path *free_path;

	if (!path)
		return ;
	free_path = path;
	while(path)
	{
		path = path->next;
		free(free_path);
		free_path = NULL;
		free_path = path;
	}
}


void	clear_beam(t_beam *beam)
{
	t_beam *free_beam;

	if (!beam)
		return ;
	free_beam = beam;
	while(beam)
	{
		beam = beam->next;
		clear_path(free_beam->path);
		free_beam->path = NULL;
		free(free_beam);
		free_beam = NULL;
		free_beam = beam;
	}
	free(beam);
	beam = NULL;
}

void	clear_beams(t_beams *beams)
{
	t_beams *tmp;
	t_beam *free_beam;
	t_beams *free_beams;

	tmp = beams;

	while (tmp)
	{
		free_beam = tmp->beam;
		if (free_beam)
			clear_beam(free_beam);
		tmp->beam = NULL;
		free_beams = tmp;
		tmp = tmp->next;
		free(free_beams);
		free_beams = NULL;
	}
}



