/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <dheidenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:16:57 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/11 19:42:38 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *p;
	char *start;

	if (!s)
		return (NULL);
	if (!f)
		return (NULL);
	p = ft_strdup((char *)s);
	if (!p)
		return (NULL);
	start = p;
	while (*s)
		*p++ = f(*s++);
	return (start);
}
