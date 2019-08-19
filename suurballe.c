


#include "lem_in.h"
#include "libft.h"
#include "queue.h"
#include "exdlst.h"


void	initialize_suurballe_search(graph *g, t_context* context)
{
	int 	i;

	i = 0;
	while(i <= MAXV)
	{
		g->color[i] = WHITE;
		g->parents[i] = -1;
		context->entry_time[i] = -1; //Можно будет убрать из структуры в функцию
		context->exit_time[i] = -1; //Можно будет убрать из структуры в функцию
		context->v_in[i] = 0;
		context->v_out[i] = 0;
		i++;
	}
	g->finished = FALSE;
}

void	duplicate_vertex(graph *g, t_context *context, int vertex)
{
	t_edgepoint edgepoint;
	t_edgenode *edgenode;
	t_edgenode *edtemp;

	//change one vertex]
	context->v_in[vertex] = TRUE;

	//create two vertex
	g->nvertices++;
	context->v_out[g->nvertices] = TRUE;
	//changes edges of vertexes
	edgepoint.x = g->nvertices;
	edgepoint.y = vertex;
	insert_edge_weight(g, &edgepoint, TRUE, 0);
	edgenode = g->edges[vertex];
	while (edgenode)
	{
		//Вставка нового ребра
		edgepoint.y = edgenode->y;
		insert_edge_weight(g, &edgepoint, TRUE, edgenode->weight);
		//Есть поле для оптимизации, если не вести поиск а добавить новую функцию добавления ребра не тольк с весом но и с значением поворота (turn)
		edtemp = get_edgenode(g, &edgepoint);
		edtemp->turn = edgenode->turn;
		//Удавление старого ребра
		remove_edge(g, edgepoint, TRUE);
		edgenode = edgenode->next;
	}
}

void	duplicate_vertexes(graph *g, t_context *context,  t_path *path)
{
	//Пропускаем старт
	path = path->next;
	//В цикле не дублируем послеюнюю вершину
	while(path->next)
	{
		duplicate_vertex(g, context, path->vertex);
		path = path->next;
	}
}

void	reverse_path(graph *g, t_context *context,  t_path *path)
{
	t_edgepoint edgepoint;

	while(path->next)
	{
		edgepoint.x = path->vertex;
		edgepoint.y = path->next->vertex;
		reverse_edge_and_weight(g, edgepoint);
		path = path->next;
	}
}

t_beam	*suurballe(graph *g, t_context *context, int start, int end)
{
	t_edgenode		*edgenode;
	t_path 			*path;
	t_beam			*beam;

//	beam = (t_beam *)ft_memalloc(sizeof(t_beam));
//	path = (t_path *)ft_memalloc(sizeof(t_path));
	graph	*gdub;
	//Zero step Suurballe
	gdub = graphdub(g);
	//One step of algorithm Suurballe
	dijkstra(gdub, start);
	//Two step reverse shortest path
	path = NULL;
	beam = NULL;
	path = find_path(start, end, gdub->parents, &path);
	add_path_to_beam(&beam, &path);
	reverse_path(gdub, context, path);
//	duplicate_vertexes(g, context, path);

	edgenode = g->edges[start]->next;
	while (edgenode)
	{
		initialize_bfs_search(gdub);
		bfs(gdub, start);
		path = NULL;

		print_array_graph(gdub->parents, "\nparent surballe dubg\n");
		print_graph(gdub);

		path = find_path(start, end, gdub->parents, &path);
		add_path_to_beam(&beam, &path);
		reverse_path(gdub, context, path);
		ft_putstr("\n");
		print_graph(gdub);
//		duplicate_vertexes(g, context, path);
		edgenode = edgenode->next;
	}

	return (beam);
}
