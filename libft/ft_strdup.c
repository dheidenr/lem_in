/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:55:47 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/08 14:53:32 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	length;
	char	*src_temp;

	length = ft_strlen(src);
	src_temp = (char *)malloc(sizeof(*src_temp) * length + 1);
	if (!src_temp)
		return (NULL);
	length = -1;
	while (src[++length] != '\0')
		src_temp[length] = src[length];
	src_temp[length] = '\0';
	return (src_temp);
}
