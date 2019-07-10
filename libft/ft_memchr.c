/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <dheidenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 20:04:56 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/04 14:18:11 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (!s && !c && !n)
		return (NULL);
	while (n--)
	{
		if (*(unsigned char*)s == (unsigned char)c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
