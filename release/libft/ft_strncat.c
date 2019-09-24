/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:03:31 by dheidenr          #+#    #+#             */
/*   Updated: 2018/11/25 15:04:47 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *temp;

	temp = s1;
	while (*temp)
		temp++;
	while (*s2 && n-- > 0)
		*temp++ = *s2++;
	*temp = '\0';
	return (s1);
}
