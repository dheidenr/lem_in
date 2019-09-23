/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearing_structures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:03:47 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/21 13:03:50 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	clear_names(char **names)
{
	char	**free_name;

	if (!names)
		return ;
	free_name = names;
	free_name++;
	while (*free_name)
	{
		free(*free_name);
		free_name++;
	}
	free(names);
}

void	clear_edgenode(t_edgenode *edge)
{
	t_edgenode *free_edge;

	if (!edge)
		return ;
	free_edge = edge;
	while (edge)
	{
		edge = edge->next;
		free(free_edge);
		free_edge = NULL;
		free_edge = edge;
	}
}

void	clear_edges(t_edgenode **edges)
{
	size_t		count;

	count = 0;
	if (!edges)
		return ;
	while (count < MAXV)
	{
		clear_edgenode(edges[count]);
		count++;
	}
}

void	clear_graph(t_graph *g)
{
	if (g)
		clear_edges(g->edges);
	free(g);
	g = NULL;
}

void	clearing_structures(t_graph *g, t_context *context)
{
	if (context)
	{
		clear_names(context->names);
		clear_edgenode(context->edgenode);
	}
	if (g)
		clear_edges(g->edges);
	if (context)
	{
		clear_beam(context->free_beam_one);
		clear_beam(context->free_beam_two);
		clear_beams(context->free_beams_one);
		clear_beams(context->free_beams_two);
	}
}
