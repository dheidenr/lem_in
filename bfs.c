/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:03:21 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/21 13:03:25 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exdlst.h"
#include "lem_in.h"
#include "aqueue.h"

void	initialize_bfs_search(t_graph *g)
{
	int				i;

	i = 0;
	while (i <= MAXV)
	{
		g->color[i] = WHITE;
		g->parents[i] = -1;
		i++;
	}
}

void	process_edge(t_graph *g)
{
	g->nedges++;
}

void	cycle_bfs(t_bfs *b, t_graph *g, int *y, const int *v)
{
	while (b->p != NULL)
	{
		(*y) = b->p->y;
		if ((g->color[(*y)] != BLACK) || (g->directed))
			process_edge(g);
		if (g->color[(*y)] == WHITE && !b->p->isolate)
		{
			enaqueue(b->q, (*y));
			g->color[(*y)] = GRAY;
			g->parents[(*y)] = (*v);
		}
		b->p = b->p->next;
	}
}

void	bfs(t_graph *g, int start)
{
	int				v;
	int				y;
	t_bfs			b;

	b.q = NULL;
	init_aqueue(&(b.q));
	enaqueue(b.q, start);
	g->color[start] = WHITE;
	while (is_empty_aqueue(b.q) == FALSE)
	{
		v = deaqueue(b.q);
		g->color[v] = BLACK;
		b.p = g->edges[v];
		cycle_bfs(&b, g, &y, &v);
	}
	v = deaqueue(b.q);
	while (v != -1)
		v = deaqueue(b.q);
	free(b.q);
}
