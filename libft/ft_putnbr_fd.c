/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <dheidenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:59:48 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/02 17:50:59 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long lnb;

	lnb = nb;
	if (lnb < 0)
	{
		ft_putchar_fd('-', fd);
		lnb *= -1;
	}
	if (lnb < 10)
	{
		ft_putchar_fd(lnb + '0', fd);
	}
	else
	{
		ft_putnbr_fd(lnb / 10, fd);
		ft_putchar_fd((lnb % 10) + '0', fd);
	}
}
