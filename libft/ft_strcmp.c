/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <dheidenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:07:27 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/04 14:42:12 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	if (!(*s1 && *s2 && (*s1 == *s2)))
		return ((unsigned char)*s1 - (unsigned char)*s2);
	while (*s1 && *s2 && (*++s1 == *++s2))
		;
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
