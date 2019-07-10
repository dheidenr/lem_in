/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:51:12 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/06 19:51:13 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_numeric(char *s)
{
	char *p;

	p = s;
	while ((size_t)(s - p) != ft_strlen(s))
		if (!ft_isdigit(*s++))
			return (0);
	return (1);
}
