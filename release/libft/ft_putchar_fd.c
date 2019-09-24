/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <dheidenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:52:33 by dheidenr          #+#    #+#             */
/*   Updated: 2018/11/28 21:40:24 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	tmp1;
	unsigned char	tmp2;

	if ((unsigned char)c < 128)
		write(fd, &c, 1);
	else
	{
		tmp1 = 192 + (unsigned char)c / 64;
		tmp2 = 128 + (unsigned char)c % 64;
		write(fd, &tmp1, 1);
		write(fd, &tmp2, 1);
	}
}
