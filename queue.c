
#include "queue.h"
#include "libft.h"
#include "lem_in.h"
#include "exdlst.h"

void	init_queue(t_queue *q)
{
	q = ft_memalloc(sizeof(t_queue));
	q->exdlist = NULL;
	q->length = 0;
}

void	enqueue(t_queue *q, int start)
{
	t_exdlist *exdlist;
	t_exdlist	*tmp;

	if (!q)
		init_queue(q);
	if (!q)
		return ;
	exdlist =  exdlstnew((void *)start, sizeof(int));
	tmp = q->exdlist;
	while (tmp->next)
	{
		tmp->end = exdlist;
		tmp = tmp->next;
	}
	exdlist->prev = tmp;
	exdlist->end = exdlist;
	exdlist->next = NULL;
	exdlist->start = tmp->start;
	tmp->next = exdlist;
	tmp->end = exdlist;
	q->length++;
}

int		dequeue(t_queue *q)
{
	t_exdlist *exdlist;
	t_exdlist	*tmp;
	int 				result;

	if (!q || !q->length)
		return (-1) ;
	exdlist = NULL;
	if (q->exdlist)
		if (q->exdlist->next)
			exdlist = q->exdlist->next;
	tmp = q->exdlist;
	result = (int)tmp->content
	while (tmp->next)
	{
		tmp->start = exdlist;
		tmp = tmp->next;
	}
	if (exdlist)
		exdlist->prev = NULL;
	q->length--;
	return (result);
}

int 		empty_queue(t_queue *q)
{
	return (q && q->exdlist &&q->length ? 0 : 1);
}

void	print_queue(t_queue *q)
{
	t_exdlist	*exdlist;

	if (q && q->exdlist)
		exdlist = q->exdlist;
	else
		exdlist = NULL;
	while (exdlist)
	{
		exdlist_int_put(exdlist);
		exdlist = exdlist->next;
		ft_putstr("\n");
	}
}