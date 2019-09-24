/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:53:29 by dheidenr          #+#    #+#             */
/*   Updated: 2018/11/28 19:59:33 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	long lnb;

	lnb = nb;
	if (lnb < 0)
	{
		ft_putchar('-');
		lnb *= -1;
	}
	if (lnb < 10)
	{
		ft_putchar(lnb + '0');
	}
	else
	{
		ft_putnbr(lnb / 10);
		ft_putchar((lnb % 10) + '0');
	}
}
