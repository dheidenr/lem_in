/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:13:08 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/08 15:27:43 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*tmp;

	if (size == 18446744073709551615U)
		return (NULL);
	tmp = (void *)malloc(size);
	if (tmp)
	{
		ft_memset(tmp, 0, size);
		return (tmp);
	}
	else
		return (NULL);
}
