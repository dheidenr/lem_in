/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:26:35 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/06 17:54:23 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_lowercase(char *s)
{
	char *p;

	p = s;
	while ((size_t)(s - p) != ft_strlen(s))
		if (!ft_islower(*s++))
			return (0);
	return (1);
}
