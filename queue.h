
#ifndef QUEUE_H
#define QUEUE_H

#include "exdlst.h"

typedef 	struct	s_queue
{
	t_exdlist	*exdlist;
	size_t 		length;
}						t_queue;

void	init_queue(t_queue **q);
void	enqueue(t_queue **q, int start);
int		dequeue(t_queue **q);
int 		empty_queue(t_queue *q);
void	print_queue(t_queue *q, int	debug);

#endif
