
#include "queue.h"
#include "lem_in.h"
#include "exdlst.h"

//t_queue *get_left_index_shortest_path(int end, int left_index, t_queue **q, graph *g)
//{
//		int i;
//
//		i = left_index;
//		init_queue(q);
//		while (i <= end)
//		{
//			enqueue(q, g->parents[i]);
//			i++;
//		}
//		enqueue(q, end);
//		return (*q);
//}
//
//t_queue *get_right_index_shortest_path(int end, int right_index, t_queue **q, graph *g)
//{
//	int i;
//
//	i = right_index;
//	init_queue(q);
//	while (i >= end)
//	{
//		enqueue(q, g->parents[i]);
//		i--;
//	}
//	enqueue(q, end);
//	return (*q);
//}
//
//void	print_path_start_end(int start, int end, int *parents)
//{
//	if (start == end || end == -1)
//		printf("\n%d", start);
//	else
//	{
//		print_path_start_end(start, parents[end], parents);
//		printf(" %d", end);
//	}
//}
//
//t_queue	*qfind_path(int start, int end, int parents[], t_queue **q)
//{
//	if (start == end || end == -1)
//		enqueue(q, start);
//	else
//	{
//		if (parents[end] == -1)
//			return (NULL);
//		qfind_path(start, parents[end], parents, q);
//		enqueue(q, end);
//	}
//	return (*q);
//}
