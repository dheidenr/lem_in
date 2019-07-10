/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:51:45 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/06 19:51:47 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_uppercase(char *s)
{
	char *p;

	p = s;
	while ((size_t)(s - p) != ft_strlen(s))
		if (!ft_isupper(*s++))
			return (0);
	return (1);
}
