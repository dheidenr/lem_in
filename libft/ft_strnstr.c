/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:46:04 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/04 14:39:56 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*p1;
	char	*p2;

	if (!*s2)
		return ((char *)s1);
	while (*s1 && n > 0)
	{
		if (*s1 == *s2)
		{
			p1 = (char *)s1;
			p2 = (char *)s2;
			while (*p2 == *p1 && *p2)
			{
				p1++;
				p2++;
			}
			if (!(*p2) && !((long long int)n
						- (long long int)ft_strlen(s2) < 0))
				return ((char *)s1);
		}
		n--;
		s1++;
	}
	return (NULL);
}
