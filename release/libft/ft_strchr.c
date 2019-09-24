/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:31:54 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/04 14:29:40 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	if (*s == '\0' && (char)c == '\0')
		return ((char *)s);
	if (*s == '\0')
		return (NULL);
	if ((char)c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	if (*s == '\0')
		return ((char *)s);
	while (*s)
		if (*s++ == (unsigned char)c)
			return ((char *)--s);
	return (NULL);
}
