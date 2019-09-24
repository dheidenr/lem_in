/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:08:08 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/21 13:08:11 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft/get_next_line.h"

int		print_gnl(const int fd, char **line)
{
	int		result;

	result = get_next_line(fd, line);
	ft_putstr(*line);
	ft_putchar('\n');
	return (result);
}

char	is_comment(char *line)
{
	if (!line)
		return (0);
	if (line[0] == '#' && line[1] != '#')
	{
		free(line);
		line = NULL;
		return (1);
	}
	return (0);
}

void	pulling_ants(t_context *context, char **line)
{
	if (print_gnl(context->fd, line))
	{
		if (*line && ft_str_is_numeric(*line))
		{
			context->global_ants = ft_atoi(*line);
			free(*line);
			line = NULL;
			if (context->global_ants <= 0)
				error();
		}
		else
			error();
	}
}

/*
** for tests change fd on open("file.txt", O_RDONLY);
*/

void	input(t_graph *g, t_context *context)
{
	char	**names;
	char	*line;
	int		fd;

	initialize_graph(g, context, 0);
	names = (char **)ft_memalloc(sizeof(char *) * MAXV);
	context->names = names;
	line = NULL;
	fd = 0;
	context->fd = fd;
	pulling_ants(context, &line);
	while (print_gnl(fd, &line))
	{
		if (is_comment(line))
			continue;
		if (!pulling_room(g, context, &line))
			if (!pulling_link(g, context, &line))
				error();
	}
	if (g->nvertices == 0 || g->nedges == 0)
		error();
	free(line);
}
