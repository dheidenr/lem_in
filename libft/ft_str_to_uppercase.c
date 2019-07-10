/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:51:45 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/14 15:27:28 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_to_uppercase(char *s)
{
	char	*p;
	char	*start;
	size_t	i;

	p = ft_strnew(ft_strlen(s));
	start = p;
	i = 0;
	while (i != ft_strlen(s))
	{
		if (ft_islower(s[i]))
		{
			p[i] = ft_toupper(s[i]);
		}
		else
		{
			p[i] = s[i];
		}
		i++;
	}
	return (start);
}
