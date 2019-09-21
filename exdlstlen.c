/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exdlstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:06:30 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/21 13:06:34 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exdlst.h"

size_t	exdlistlen(t_exdlist *stack)
{
	size_t	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
