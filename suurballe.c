
#include "lem_in.h"
#include "libft.h"
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
	context->in_out_vertices++;
//	context->v_out[context->in_out_vertices] = TRUE;
	context->v_out[context->in_out_vertices] = vertex;
	//changes edges of vertexes
	edgepoint.x = vertex;
	edgepoint.y = g->nvertices;

	insert_edge_weight(g, &edgepoint, TRUE, 0);

	edgenode = g->edges[vertex]->next;


	while (edgenode)
	{
		edgepoint.x = g->nvertices;
		//Вставка нового ребра
		edgepoint.y = edgenode->y;
		insert_edge_weight(g, &edgepoint, TRUE, edgenode->weight);
		//Есть поле для оптимизации, если не вести поиск а добавить новую функцию добавления ребра не тольк с весом но и с значением поворота (turn)
		edtemp = get_edgenode(g, &edgepoint);
		edtemp->turn = edgenode->turn;
		//Удавление старого ребра
		edgepoint.x = vertex;
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

void	duplicate_all_vertexes_graph(graph *g, t_context *context, int start, int end)
{
	size_t	vertex;

	//Пропускаем старт
	vertex = 1;
	while(vertex < g->nvertices - context->in_out_vertices)
	{
		if (vertex != start && vertex != end && !context->v_in[vertex])
			duplicate_vertex(g, context, vertex);
		vertex++;
	}
}


void	reverse_path(graph *g, t_context *context,  t_path *path)
{
	t_edgepoint edgepoint;

	if (!path)
		return ;
	while(path->next)
	{
		edgepoint.x = path->vertex;
		edgepoint.y = path->next->vertex;
		reverse_edge_and_weight(g, edgepoint);
		path = path->next;
	}
}

void 	remove_fake_vertex(graph *g, t_context *context, int	vertex, t_path **path)
{
	t_path	*prev;
	t_path	*tmp;
	t_path *start;

	start = *path;
	prev = *path;
	while (*path)
	{
		if (vertex == (*path)->vertex)
		{
			if (prev && prev == (*path))
			{
				*path = (*path)->next;
				free((prev));
				prev = NULL;
			}
			else if (prev && *path)
			{
				tmp = *path;
				if (prev->vertex != context->v_out[(*path)->vertex - (g->nvertices - context->in_out_vertices)] // (*path)->vertex - (g->nvertices - context->in_out_vertices) + 1
					&& (*path)->next->vertex != context->v_out[(*path)->vertex - (g->nvertices - context->in_out_vertices)]) // != (*path)->vertex - (g->nvertices - context->in_out_vertices) + 1)
//					&& (*path)->vertex > g->nvertices - context->in_out_vertices
//					&& prev != *path
//					&& prev->vertex != 1) // кастыль?
				{
					(*path)->vertex = context->v_out[(*path)->vertex - (g->nvertices - context->in_out_vertices)]; // (*path)->vertex - (g->nvertices - context->in_out_vertices) + 1;
					*path = start;
					return ;
				}
				prev->next = (*path)->next;
//				*path = (*path)->next;
				*path = start;
				free((tmp));
				tmp = NULL;
				return ;
			} else
			{
				*path = NULL;
			}
		} else
		{
			prev = *path;
			(*path) = (*path)->next;
		}
	}
}

void	remove_fake_vertexes(graph *g, t_context *context, t_path **path)
{
	t_path *tmp;

	tmp = *path;
	while(tmp)
	{
		if (tmp->vertex > g->nvertices - context->in_out_vertices)
			remove_fake_vertex(g, context, tmp->vertex, path);
		tmp = tmp->next;
	}
}

void	isolate_edgenode(t_edgenode *edgenode, char isolate)
{
	while (edgenode)
	{
		edgenode->isolate = isolate;
		edgenode = edgenode->next;
	}
}

void 	isolate_all_edges(graph *g)
{
	size_t 	count;
	t_edgenode	*edgenode;

	count = 1;
	while (count <= g->nvertices)
	{
		edgenode = g->edges[count];
		while (edgenode)
		{
			edgenode->isolate = TRUE;
			edgenode = edgenode->next;
		}
		count++;
	}
}

t_edgepoint	*reverse_edgepoint(t_edgepoint *edgepoint, t_edgepoint *reverse_edge)
{
	reverse_edge->x = edgepoint->y;
	reverse_edge->y = edgepoint->x;
	return (reverse_edge);
}

void 	no_isolate_all_edges_of_beam(graph *g, t_beam *beam)
{
	t_path		*path;
	t_edgenode	*edgenode;
	t_edgepoint edp;
	t_edgenode *reverse_edge;
	t_edgepoint *rev_edp;

	rev_edp = (t_edgepoint *)ft_memalloc(sizeof(t_edgepoint));
	while (beam)
	{
		path = beam->path;
		edp.x = path->vertex;
		path = path->next;
		while (path)
		{
			edp.y = path->vertex;
			edgenode = get_edgenode(g, &edp);
			if (edgenode)
			{
				reverse_edge = get_edgenode(g, reverse_edgepoint(&edp, rev_edp));
				edgenode->turn++;
				if (edgenode->turn > 0 && reverse_edge->turn > 0)
				{
					edgenode->isolate = TRUE;
					reverse_edge->isolate = TRUE;
				}
				if (edgenode->turn + reverse_edge->turn < 2)
					edgenode->isolate = FALSE;
				else
					edgenode->isolate = TRUE;
			}
			path = path->next;
			edp.x = edp.y;
		}
		beam = beam->next;
	}
}

t_beam *find_true_beam(graph *g, t_context *context, t_beam *fake_beam, t_edgepoint start_end)
{
	t_beam *true_beam;
	t_path	*path;
	t_edgenode *edgenode;
	t_edgenode *tmp_edge;
	t_edgepoint tmp_point;

	//Добавить функцию которая изаллирует все ребра.
	isolate_all_edges(g);
	//Добавить функцию помечающую ребра которые входят в пути как не изаллированные и удаляет ребра перевернутого(пометить изаллированным)
	no_isolate_all_edges_of_beam(g, fake_beam);

	ft_putstr("\nafter isolate_all_edges and no_isolate_all_edges_of_beam \n");
	print_graph(g);
	path = NULL;
	true_beam = NULL;//(t_beam *)malloc(sizeof(t_beam));
	edgenode = g->edges[start_end.x];
	isolate_edgenode(edgenode, TRUE);

	tmp_point.x = start_end.x;
	while(fake_beam)
	{
		//Получаем номер следующей вершины после старта в текущем пути
		tmp_point.y = fake_beam->path->next->vertex;
		tmp_edge = get_edgenode(g, &tmp_point);
		tmp_edge->isolate = FALSE;

		initialize_bfs_search(g);
		bfs(g, start_end.x);//Popravit' bfs dlya isolate
		path = NULL;
		path = find_path(start_end.x, start_end.y, g->parents, &path);
		add_path_to_beam(&true_beam, &path, get_length_path(path));
		tmp_edge->isolate = TRUE;
		fake_beam = fake_beam->next;
	}
	isolate_edgenode(edgenode, FALSE);
	return (true_beam);
}

t_beam	*suurballe(graph *g, t_context *context, int start, int end)
{
//	t_edgenode		*edgenode;
	t_edgepoint		start_end;
	t_path 			*path;
	t_beam			*beam;
	size_t			i;

	i = 1;
	start_end.x = start;
	start_end.y = end;
//	beam = (t_beam *)ft_memalloc(sizeof(t_beam));
//	path = (t_path *)ft_memalloc(sizeof(t_path));
	graph	*gdub;
	//Zero step Suurballe
	gdub = graphdub(g);
	//non duplicate
	//1: 1 2 4 6
	//2: 1 3 4 2 5 6
	//after duplicate
	//1: 1 2 7 4 9 6
	//2: 1 3 8 4 7 5 10 6
	duplicate_all_vertexes_graph(gdub, context, start, end);
	//One step of algorithm Suurballe
	initialize_bfs_search(gdub);
	bfs(gdub, start);
	//Two step reverse shortest path
	path = NULL;
	beam = NULL;
	path = find_path(start, end, gdub->parents, &path);
	ft_putstr("before add path null duplicate vertexes\n");
	print_graph(gdub);
	print_array_graph(gdub->parents, gdub, "\nparent surrballe dubg\n");

	reverse_path(gdub, context, path);
	remove_fake_vertexes(gdub, context, &path);
	add_path_to_beam(&beam, &path, get_length_path(path));

//	duplicate_vertexes(g, context, path);

//	edgenode = g->edges[start]->next;
	while (i <= g->degree[start])
	{
		initialize_bfs_search(gdub);
		bfs(gdub, start);
		path = NULL;
		print_array_graph(gdub->parents, gdub,  "\nparent surrballe dubg\n");
		print_graph(gdub);
		path = find_path(start, end, gdub->parents, &path);

		if (!path)
			break ;
		reverse_path(gdub, context, path);
		remove_fake_vertexes(gdub, context, &path);
		add_path_to_beam(&beam, &path, get_length_path(path));
		ft_putstr("\n");
		print_graph(gdub);
//		duplicate_vertexes(g, context, path);
		i++;
//		edgenode = edgenode->next;
	}
	ft_putstr("\n before find suurballe beam:\n");
	print_beam(beam);
	if (get_length_beam(beam) > 1)
		beam = find_true_beam(g, context, beam, start_end);
	ft_putstr("\n after find suurballe beam:\n");
	print_beam(beam);

//	duplicate_vertex(gdub, context, 3);
//	ft_putstr("\nafter duplicate vertex\n");
//	print_graph(gdub);
	return (beam);
}
