/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:51:31 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/06 19:51:32 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_printable(char *s)
{
	char *p;

	p = s;
	while ((size_t)(s - p) != ft_strlen(s))
		if (!ft_isprint(*s++))
			return (0);
	return (1);
}
