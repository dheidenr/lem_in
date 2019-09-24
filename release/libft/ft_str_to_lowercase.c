/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:26:35 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/14 15:25:32 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_to_lowercase(char *s)
{
	char	*p;
	char	*start;
	size_t	i;

	p = NULL;
	p = ft_strnew(ft_strlen(s));
	start = p;
	i = 0;
	while (i != ft_strlen(s))
	{
		if (ft_isupper(s[i]))
		{
			p[i] = ft_tolower(s[i]);
		}
		else
		{
			p[i] = s[i];
		}
		i++;
	}
	return (start);
}
