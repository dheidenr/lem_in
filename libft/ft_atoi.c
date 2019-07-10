/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:53:04 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/08 14:50:53 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			test_long(unsigned long long num, int m, size_t check)
{
	if (num > 9223372036854775807 || num / 10 != check)
		return (m > 0 ? 0 : -1);
	return (1);
}

int					ft_atoi(const char *st)
{
	int					m;
	unsigned long long	num;
	size_t				check;

	check = 0;
	m = 0;
	num = 0;
	while ((*st >= 9 && *st <= 13) || *st == ' ')
		st++;
	if (*st == '+' || *st == '-')
	{
		if (*st == '-')
			m++;
		st++;
	}
	while (*st >= '0' && *st <= '9')
	{
		check = num;
		num = num * 10;
		num = num + *st - '0';
		if (test_long(num, m, check) != 1)
			return (test_long(num, m, check));
		st++;
	}
	return (m > 0 ? -num : num);
}
