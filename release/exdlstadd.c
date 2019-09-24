/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exdlstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:05:15 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/21 13:05:18 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exdlst.h"

void	exdlstadd(t_exdlist **aexdlst, t_exdlist *new)
{
	if (aexdlst == NULL || new == NULL)
		return ;
	new->next = *aexdlst;
	(*aexdlst)->prev = new;
	new->start = new;
	new->end = (*aexdlst)->end;
	*aexdlst = new;
}
