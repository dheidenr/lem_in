
#include "lem_in.h"
#include "libft/get_next_line.h"

int 	print_gnl(const int fd, char **line)
{
	int		result;

	result = get_next_line(fd, line);
	ft_putstr(*line);
	ft_putchar('\n');
	return (result);
}

char 	is_comment(char *line)
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
		}
		else
			error();
	}
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
	//если коментарий пропустить, если две решетки проверить на старт и следующ ий определить
	//Если цифра и потом

	fd = open("ant_gen.txt", O_RDONLY);
//	fd = 0;
	context->fd = fd;
	pulling_ants(context, &line);

	while (print_gnl(fd, &line))
	{
		if (is_comment(line))
			continue;
		if (!pulling_room(g, context, &line))
			if (!pulling_link(g, context, line))
				error();
	}
	free(line);
}

