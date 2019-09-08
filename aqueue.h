#ifndef LEM_IN_AQUEUE_H
#define LEM_IN_AQUEUE_H

# include <unistd.h>
# include <stdlib.h>
#include "lem_in.h"

typedef 	struct	s_aqueue
{
	int 		elements[MAXV + 1];
	size_t		cursor;
	size_t		end;
	size_t 		length;
}						t_aqueue;

void	init_aqueue(t_aqueue **q);
void	enaqueue(t_aqueue *q, int src);
int		deaqueue(t_aqueue *q);
int 	is_empty_aqueue(t_aqueue *q);
void	print_aqueue(t_aqueue *q);
#endif
