

#include "lem_in.h"
#include "get_next_line.h"

char 	is_comment(const char *line)
{
	if (!line)
		return (0);
	if (line[0] == '#' && line[1] != '#')
		return (1);
	return (0);
}

void	pulling_ants(int fd, t_context *context, char *line)
{
	if (get_next_line(fd, &line))
	{
		if (line && ft_str_is_numeric(line))
			context->global_ants = ft_atoi(line);
		else
			error();
	}
}

size_t	pulling_room(graph *g, t_context *context, int fd, char **line)
{
	const char	*str;
	size_t		len;
	char 		*name;
	size_t 		index;

	index = 1;
	len = 0;
	str = *line;
	if (!*line)
		return (0);
	if (ft_strcmp("##start", *line) == 0)
	{
		get_next_line(fd, line);
		context->start = pulling_room(g, context, fd, line);
		return (context->start);
	}
	if (ft_strcmp("##end", *line) == 0)
	{
		get_next_line(fd, line);
		context->end = pulling_room(g, context,fd, line);
		return (context->end);
	}

	if (ft_strchr(str, '-'))
		return (0);
	while(ft_isspace(*str))
		str++;
	//get name room
	while (!ft_isspace(str[len]))
		len++;
	name = ft_strsub(str, 0, len);
	while (!ft_isspace(*str))
		str++;

	while (context->names[index] != NULL)
		index++;
	context->names[index] = name;
	//get x and y?
	g->nvertices = index;
	return (index);
}

int	get_index_of_link(char *link, t_context *context)
{
	int		index;

	index = 0;
	if (!link)
		return (0);
	while (context->names[++index] != NULL)
		if (ft_strcmp(context->names[index], link) == 0)
			return (index);
	return (0);
}

char 	pulling_link(graph *g, t_context *context, const char *line)
{
	const char	*str;
	size_t		len;
	char 		*link_one;
	char		*link_two;

	len = 0;
	str = line;
	if (!line)
		return (0);
	if (!ft_strchr(str, '-'))
		return (0);
	while(ft_isspace(*str))
		str++;
	//get name link1
	while (str[len] != '-' && str[len] != '\0')
		len++;
	link_one = ft_strsub(str, 0, len);
	while (*str != '-' && *str != '\0')
		str++;
	str++;
	len = 0;
	//get name link2
	while (str[len] != '-' && str[len] != '\0')
		len++;
	link_two = ft_strsub(str, 0, len);
	while (*str != '-' && *str != '\0')
		str++;
	insert_edge(g, get_index_of_link(link_one, context), get_index_of_link(link_two, context), 0);
	return (1);
}
void	input(graph *g, t_context *context)
{
	char	**names;
	char 	*line;
	int 	fd;

	initialize_graph(g, context, 0);
	names = (char **)ft_memalloc(sizeof(char *) * MAXV);
	context->names = names;
	line = NULL;
	//получить строку
	//обработать строку на ошибки
	//взять данные из строки в граф
	//взять данные из строки в names для имен
	//если коментарий пропустить, если две решетки проверить на старт и следующий определить
	//Если цифра и потом

	fd = open("ant2.txt", O_RDONLY);
	pulling_ants(fd, context, line);

	while (get_next_line(fd, &line))
	{
		if (is_comment(line))
			continue ;
		if (!pulling_room(g, context,fd, &line))
			if (!pulling_link(g, context, line))
				error();
	}
}