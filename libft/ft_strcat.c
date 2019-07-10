/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:03:31 by dheidenr          #+#    #+#             */
/*   Updated: 2018/11/25 15:04:47 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char *temp;

	temp = dest;
	while (*temp)
		temp++;
	while (*src)
		*temp++ = *src++;
	*temp = '\0';
	return (dest);
}
