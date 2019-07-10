/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:23:35 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/04 14:26:55 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	all_size;
	char	*tmp;

	tmp = dst;
	while (*dst)
		dst++;
	all_size = (size_t)(dst - tmp) + ft_strlen(src);
	if (size <= (size_t)(dst - tmp))
		return (ft_strlen(src) + size);
	size -= (size_t)(dst - tmp);
	while (*src)
		if (size-- < 2)
		{
			*dst = '\0';
			return (all_size);
		}
		else
			*dst++ = *src++;
	*dst = '\0';
	return (all_size);
}
