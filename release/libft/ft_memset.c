/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:02:50 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/02 17:18:55 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	void *tmp;

	tmp = b;
	while (len)
	{
		*((char *)b) = (unsigned char)c;
		b++;
		len--;
	}
	return (tmp);
}
