/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:46:28 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/02 17:47:45 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *tmp;
	char *p;

	if (!s1 || !s2)
		return (NULL);
	tmp = (char *)malloc(sizeof(*tmp) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!tmp)
		return (NULL);
	p = tmp;
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = '\0';
	return (p);
}
