/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <dheidenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:01:02 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/04 14:03:12 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n)
	{
		if (*s == (unsigned char)c)
		{
			*d = *s;
			d++;
			s++;
			return (d);
		}
		else
		{
			*d = *s;
			d++;
			s++;
		}
		n--;
	}
	return (NULL);
}
