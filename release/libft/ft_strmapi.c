/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <dheidenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:35:38 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/04 15:14:40 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	char			*start;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!f)
		return (NULL);
	p = ft_strdup((char *)s);
	if (!p)
		return (NULL);
	start = p;
	while (*s)
	{
		*p = f(i, *s);
		p++;
		s++;
		i++;
	}
	return (start);
}
