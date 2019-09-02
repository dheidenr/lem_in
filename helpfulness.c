
#include "lem_in.h"

void	error()
{
	ft_putstr("Error");
	exit(0);
}

size_t	get_length_path(t_path *path)
{
	size_t	len;
	t_path	*tmp;

	len = 0;
	tmp = path;
	if (!path)
		return (0);
	while(tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

size_t	get_length_paths(t_beam *beam)
{
	size_t	len;
	t_beam	*tmp;

	len = 0;
	tmp = beam;
	while(tmp)
	{
		len += tmp->length;
		tmp = tmp->next;
	}
	return (len);
}

size_t	get_length_beam(t_beam *beam)
{
	size_t	len;
	t_beam	*tmp;

	len = 0;
	tmp = beam;
	while(tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
