/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:53:23 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/14 13:53:25 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	size_t	length;
	char	*src_temp;

	length = ft_strlen(src);
	src_temp = (char *)malloc(sizeof(*src_temp) * length + 1);
	if (!src_temp)
		return (NULL);
	length = -1;
	while (src[++length] != '\0' && n)
	{
		src_temp[length] = src[length];
		n--;
	}
	src_temp[length] = '\0';
	return (src_temp);
}
