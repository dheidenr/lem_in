/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_element.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:08:18 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/21 13:08:21 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_element_in_path(int nb, t_path *path)
{
	t_path	*tmp;

	if (!path)
		return (0);
	tmp = path;
	tmp = tmp->next;
	if (!tmp)
		return (0);
	while (tmp->next)
	{
		if (tmp->vertex == nb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		is_element_in_beam(int nb, t_beam *beam)
{
	t_beam	*tmp;

	if (!beam)
		return (0);
	tmp = beam;
	while (tmp)
	{
		if (is_element_in_path(nb, tmp->path))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		is_elements_of_path_in_beam(t_beam *beam, t_path *path)
{
	t_path	*tmp;

	if (!path || !beam)
		return (0);
	tmp = path;
	tmp = tmp->next;
	if (!tmp)
		return (0);
	while (tmp->next)
	{
		if (is_element_in_beam(tmp->vertex, beam))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
