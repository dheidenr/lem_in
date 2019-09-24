/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aqueue.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:02:53 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/21 13:02:56 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aqueue.h"
#include "libft/libft.h"
#include "exdlst.h"

void	init_aqueue(t_aqueue **q)
{
	*q = ft_memalloc(sizeof(t_aqueue));
	ft_memset((*q)->elements, 0, sizeof(t_aqueue));
	(*q)->cursor = 0;
	(*q)->end = 0;
	(*q)->length = 0;
}

void	enaqueue(t_aqueue *q, int src)
{
	q->elements[q->end] = src;
	q->end++;
	q->length = q->end - q->cursor;
}

int		deaqueue(t_aqueue *q)
{
	int		result;

	if (!q->length)
		return (-1);
	result = q->elements[q->cursor];
	q->cursor++;
	q->length = q->end - q->cursor;
	return (result);
}

int		is_empty_aqueue(t_aqueue *q)
{
	return (q && q->length ? 0 : 1);
}

void	print_aqueue(t_aqueue *q)
{
	size_t		count;

	if (is_empty_aqueue(q))
		ft_putstr("Null\n");
	count = q->cursor;
	while (count < q->end)
	{
		ft_putnbr(q->elements[count]);
		ft_putstr(" ");
		count++;
	}
	ft_putstr("\n");
}
