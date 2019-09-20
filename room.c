
#include "lem_in.h"

void	fill_name_room(const char **str, int len, size_t *index, t_context *context)
{
	char *name;

	name = ft_strsub(*str, 0, len);
	while (!ft_isspace(**str))
		(*str)++;
	while (context->names[*index] != NULL)
		(*index)++;
	context->names[*index] = name;
}

size_t	pulling_room(t_graph *g, t_context *context, char **line)
{
	const char	*str;
	size_t		len;
	size_t 		index;

	index = 1;
	len = 0;
	str = *line;
	if (!*line)
		return (0);
	if (ft_strcmp("##start", *line) == 0)
		return (ending_room(&(context->start), context, &line, g));
	if (ft_strcmp("##end", *line) == 0)
		return (ending_room(&(context->end), context, &line, g));
	if (ft_strchr(str, '-'))
		return (0);
	while(ft_isspace(*str))
		str++;
	while (!ft_isspace(str[len]))
		len++;
	fill_name_room(&str, len, &index, context);
	g->nvertices = index;
	free(*line);
	*line = NULL;
	return (index);
}

int 	ending_room(int *ending, t_context *context, char ***line, t_graph *g)
{
	free(**line);
	**line = NULL;
	print_gnl(context->fd, *line);
	*ending = pulling_room(g, context, *line);
	return (*ending);
}

