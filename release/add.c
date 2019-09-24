/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:02:32 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/21 13:02:35 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_path_len_null_in_beam(t_beam *beamtemp, t_path **path, size_t len)
{
	beamtemp->next = NULL;
	beamtemp->path = *path;
	beamtemp->length = len;
	beamtemp->ants = 0;
	beamtemp->isolate = 0;
}

void	add_path_to_beam(t_beam **beam, t_path **path, size_t len)
{
	t_beam		*beamtemp;
	t_beam		*start_beam;

	if (!*path)
		return ;
	if (!*beam)
	{
		*beam = (t_beam *)ft_memalloc(sizeof(t_beam));
		set_path_len_null_in_beam(*beam, path, len);
	}
	else
	{
		start_beam = *beam;
		while ((*beam)->next)
			*beam = (*beam)->next;
		beamtemp = (t_beam *)ft_memalloc(sizeof(t_beam));
		set_path_len_null_in_beam(beamtemp, path, len);
		(*beam)->next = beamtemp;
		*beam = start_beam;
	}
}

void	add_vertex_to_path(t_path **path, int vertex)
{
	t_path			*temppath;
	static	t_path	*temp;

	if (!*path)
	{
		*path = malloc(sizeof(t_path));
		(*path)->next = NULL;
		(*path)->vertex = vertex;
		(*path)->ant = 0;
		temp = *path;
	}
	else
	{
		while ((*path)->next)
			(*path) = (*path)->next;
		temppath = (t_path *)ft_memalloc(sizeof(t_path));
		temppath->vertex = vertex;
		temppath->ant = 0;
		temppath->next = NULL;
		(*path)->next = temppath;
	}
	*path = temp;
}
