/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aqueue.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:03:03 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/21 13:03:06 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_AQUEUE_H
#define LEM_IN_AQUEUE_H

# include <unistd.h>
# include <stdlib.h>
#include "lem_in.h"

typedef 	struct	s_aqueue
{
	int 				elements[MAXV + 1];
	size_t				cursor;
	size_t				end;
	size_t 				length;
}						t_aqueue;

typedef struct 		s_bfs
{
	t_aqueue		*q;
	t_edgenode		*p;
}					t_bfs;

void				init_aqueue(t_aqueue **q);
void				enaqueue(t_aqueue *q, int src);
int					deaqueue(t_aqueue *q);
int 				is_empty_aqueue(t_aqueue *q);
void				print_aqueue(t_aqueue *q);
#endif
