/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:15:00 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/04 15:32:45 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	swap(char **end, const char **s, char **start)
{
	*end = (char *)*s;
	*s = *start;
	*start = *end;
	*s += ft_strlen(*s) - 1;
}

char			*ft_strtrim(char const *s)
{
	char		*start;
	char		*end;
	char		*tmp;

	if (!s)
		return (NULL);
	start = (char *)s;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (*s == '\0')
		return (ft_strnew(1));
	swap(&end, &s, &start);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s--;
	end = (char *)s;
	if (!(tmp = (char *)malloc(sizeof(*tmp) * (end - start + 1) + 1)))
		return (NULL);
	*(tmp + (end - start) + 1) = '\0';
	s = start;
	start = tmp;
	while (s != end)
		*tmp++ = *s++;
	*tmp = *s;
	return (start);
}
