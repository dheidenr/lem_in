/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:44:51 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/02 17:48:13 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *tmp;
	char *p;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
	{
		if (!(tmp = (char *)malloc(1)))
			return (NULL);
		else
			return ((*tmp = '\0') ? NULL : tmp);
	}
	if (!(tmp = (char *)malloc(sizeof(*tmp) * len + 1)))
		return (NULL);
	p = tmp;
	while (len)
	{
		*tmp = s[start];
		start++;
		len--;
		tmp++;
	}
	*tmp = '\0';
	return (p);
}
