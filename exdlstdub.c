/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exdlstdub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:05:54 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/21 13:05:57 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exdlst.h"

t_exdlist	*exdlstdub_int(t_exdlist *stack)
{
	t_exdlist	*temp;
	t_exdlist	*exdlst;

	exdlst = stack;
	if (!stack)
		return (NULL);
	while (exdlst->next)
		exdlst = exdlst->next;
	temp = NULL;
	while (exdlst)
	{
		if (!exdlst->next)
			temp = exdlstnew((int *)exdlst->content,
					sizeof(*(int *)exdlst->content));
		else
			exdlstadd(&temp, exdlstnew((int *)exdlst->content,
					sizeof(*(int *)exdlst->content)));
		exdlst = exdlst->prev;
	}
	return (temp);
}
