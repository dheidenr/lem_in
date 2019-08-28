
#include "lem_in.h"

void	error()
{
	ft_putstr("Error");
	exit(0);
}

size_t	get_length_path(t_path *path)
{
	size_t	len;

	len = 0;
	while (path)
	{
		len++;
		path = path->next;
	}
	return (len);
}