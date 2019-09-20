
#include "lem_in.h"

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

void	get_links(char *str, char **link_one, char **link_two)
{
	size_t		len;

	len = 0;
	while (str[len] != '-' && str[len] != '\0')
		len++;
	*link_one = ft_strsub(str, 0, len);

	while (*str != '-' && *str != '\0')
		str++;
	str++;
	len = 0;
	while (str[len] != '-' && str[len] != '\0')
		len++;
	*link_two = ft_strsub(str, 0, len);
	while (*str != '-' && *str != '\0')
		str++;
}

char 	pulling_link(t_graph *g, t_context *context, char *line)
{
	char	*str;
	char 		*link_one;
	char		*link_two;

	str = line;
	if (!line)
		return (0);
	if (!ft_strchr(str, '-'))
		return (0);
	while(ft_isspace(*str))
		str++;
	get_links(str, &link_one, &link_two);
	insert_edge(g, get_index_of_link(link_one, context), get_index_of_link(link_two, context), 0);
	free(line);
	line = NULL;
	free(link_one);
	link_one = NULL;
	free(link_two);
	link_two = NULL;
	return (1);
}
