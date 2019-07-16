
#include "libft.h"
#include "queue.h"
#include "lem_in.h"
#include "exdlst.h"

t_queue *get_left_index_shortest_path(int end, int left_index, t_queue **q, graph *g)
{
	int i;

		i = left_index;
		init_queue(q);
		while (i <= end)
		{
			enqueue(q, g->parent[i]);
			i++;
		}
		enqueue(q, end);
		return (*q);
}

t_queue *get_right_index_shortest_path(int end, int right_index, t_queue **q, graph *g)
{
	int i;

	i = right_index;
	init_queue(q);
	while (i >= end)
	{
		enqueue(q, g->parent[i]);
		i--;
	}
	enqueue(q, end);
	return (*q);
}

t_queue *shortest_bfs_path_search(graph *g, int start, int end)
{
	int	left_index;
	int 	right_index;
	t_queue	*q;
	int 	i;

	i = 1;
	left_index = MAXV;
	right_index =  MAXV;

	while (i <= end)
	{
		if (g->parent[i] == start)
			left_index = i;
		i++;
	}
	i--;
	while (i <= g->nvertices)
	{
		if (g->parent[i] == -1)
			right_index = MAXV;
		if (g->parent[i] == start)
		{
			right_index = i;
			break;
		}
		i++;
	}

	if (right_index == MAXV && left_index != MAXV)
		return (get_left_index_shortest_path(end, left_index, &q, g));
	else if (right_index != MAXV && left_index == MAXV)
		return (get_right_index_shortest_path(end, right_index, &q, g));
	else if (end - left_index < right_index - end)
		return (get_left_index_shortest_path(end, left_index, &q, g));
	else
		return (get_right_index_shortest_path(end, right_index, &q, g));
//	{
//		//		true_index = left_index;
//		i = left_index;
//		init_queue(&q);
//
//		while (i <= end)
//		{
//			enqueue(&q, g->parent[i]);
//			i++;
//		}
//		enqueue(&q, end);
//		return (q);
//	}
//	else
//	{
//		//		true_index = right_index;
//		i = right_index;
//		init_queue(&q);
//		while (i >= end)
//		{
//			enqueue(&q, g->parent[i]);
//			i--;
//		}
//		enqueue(&q, end);
//		return (q);
//	}
}

void	find_path(int start, int end, int *parents)
{
	if (start == end || end == -1)
		printf("\n%d", start);
	else
	{
		find_path(start, parents[end], parents);
		printf(" %d", end);
	}
}

t_queue	*qfind_path(int start, int end, int parents[], t_queue **q)
{

	if (start == end || end == -1)
	{
//		printf("\n%d", start);
		enqueue(q, start);
	}
	else
	{
		qfind_path(start, parents[end], parents, q);
		enqueue(q, end);
//		printf(" %d", end);
	}
	return (*q);
}