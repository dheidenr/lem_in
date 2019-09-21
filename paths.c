/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:09:36 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/21 13:09:40 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	swap_paths(t_beam *one, t_beam *two)
{
	t_path	*path;
	size_t	tmp;
	char	isolate;

	if (!one || !two || one == two)
		return ;
	tmp = one->length;
	one->length = two->length;
	two->length = tmp;
	tmp = one->ants;
	one->ants = two->ants;
	two->ants = tmp;
	isolate = one->isolate;
	one->isolate = two->isolate;
	two->isolate = isolate;
	path = one->path;
	one->path = two->path;
	two->path = path;
}
