/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <dheidenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:34:15 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/04 14:32:25 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *p;

	if (*s == '\0' && (char)c == '\0')
		return ((char *)s);
	p = NULL;
	if (*s == '\0')
		return (NULL);
	if (*s == (unsigned char)c)
		p = s;
	if (*s == '\0')
		return ((char *)s);
	while (*s++)
		if (*s == (unsigned char)c)
			p = s;
	return ((char *)p);
}
