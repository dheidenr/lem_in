/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <dheidenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:11:15 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/10 14:49:47 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**clean_str(size_t length, char ***freeman)
{
	char		**p;
	size_t		count;

	count = 0;
	p = *freeman;
	while (count < length)
		free(p[count]);
	free(p);
	p = NULL;
	*freeman = p;
	return (NULL);
}

static	size_t	count_worlds(const char *s, char c)
{
	size_t		count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		num_worlds;
	char		**tmp;
	size_t		i;
	size_t		len;

	i = 0;
	if (!s)
		return (NULL);
	num_worlds = count_worlds(s, c);
	if (!(tmp = (char **)malloc(sizeof(*tmp) * (count_worlds(s, c) + 1))))
		return (NULL);
	while ((num_worlds--) && *s)
	{
		len = 0;
		while (*s == c)
			s++;
		while (s[len] != c && s[len])
			len++;
		tmp[i] = ft_strsub(s, 0, len);
		if (!tmp[i++])
			return (clean_str(i - 1, &tmp));
		s += len;
	}
	tmp[i] = NULL;
	return (tmp);
}
