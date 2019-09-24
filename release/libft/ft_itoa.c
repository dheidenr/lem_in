/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <dheidenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:19:29 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/04 15:42:19 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void		end(int *n, int *m, long int *num, size_t *dec)
{
	*num = *n;
	while (*n /= 10)
		(*dec)++;
	if (*num < 0 && (*m = 2))
		(*num) *= -1;
}

static	void		num_dec(const long int *num, size_t *dec)
{
	*dec = 1;
	while (*dec <= (size_t)(*num / 10))
		*dec = *dec * 10;
}

char				*ft_itoa(int n)
{
	int				m;
	long int		num;
	size_t			dec;
	char			*res;
	char			*tmp;

	m = 1;
	dec = 1;
	end(&n, &m, &num, &dec);
	res = (char *)ft_memalloc(sizeof(*res) * dec + m);
	if (!res)
		return (NULL);
	tmp = res;
	res[dec] = '\0';
	if (m == 2)
		*res++ = '-';
	num_dec(&num, &dec);
	while (dec != 0)
	{
		*res++ = (char)(num / dec + '0');
		num = (char)(num % dec);
		dec = dec / 10;
	}
	*res = '\0';
	return (tmp);
}
