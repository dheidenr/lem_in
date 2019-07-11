
#include "libft.h"
#include "queue.h"
#include "lem_in.h"
#include "exdlst.h"

t_queue *shortest_path_search(graph *g, int	start, int end)
{
	int	left_index;
	int 	right_index;
	t_queue	*q;
	int 	true_index;
	int 	v;
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
	if (end - left_index < g->nvertices - end + right_index)
	{
		//		true_index = left_index;
		i = left_index;
		init_queue(&q);

		while (i <= end)
		{
			enqueue(&q, g->parent[i]);
			i++;
		}
		enqueue(&q, end);
		return (q);
	}
	else
	{
		//		true_index = right_index;
		i = right_index;
		init_queue(&q);
		while (i >= end)
		{
			enqueue(&q, g->parent[i]);
			i--;
		}
		enqueue(&q, end);
		return (q);
	}
}