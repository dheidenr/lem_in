/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:09:18 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/08 13:53:26 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	unsigned char	tmp1;
	unsigned char	tmp2;

	if ((unsigned char)c < 128)
		write(1, &c, 1);
	else
	{
		tmp1 = 192 + (unsigned char)c / 64;
		tmp2 = 128 + (unsigned char)c % 64;
		write(1, &tmp1, 1);
		write(1, &tmp2, 1);
	}
}
