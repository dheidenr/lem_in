/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <dheidenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:08:31 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/04 15:05:53 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (size + 1 == 0)
		return (NULL);
	tmp = (char *)malloc(size + 1);
	if (tmp)
	{
		while (i <= size)
			tmp[i++] = '\0';
		return (tmp);
	}
	return (NULL);
}
