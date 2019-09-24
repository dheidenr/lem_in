/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exdlstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:05:28 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/21 13:05:33 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exdlst.h"

void	exdlstdel(t_exdlist **aexdlist, void (*del)(void *, size_t))
{
	t_exdlist *next_exlst;

	if (*aexdlist == NULL || !aexdlist || !del)
		return ;
	while (*aexdlist)
	{
		next_exlst = (*aexdlist)->next;
		del((*aexdlist)->content, (*aexdlist)->content_size);
		free((*aexdlist));
		*aexdlist = NULL;
		(*aexdlist)->start = NULL;
		(*aexdlist)->end = NULL;
		*aexdlist = next_exlst;
	}
	*aexdlist = NULL;
}
