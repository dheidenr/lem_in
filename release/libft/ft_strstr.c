/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:46:04 by dheidenr          #+#    #+#             */
/*   Updated: 2018/12/04 14:35:01 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t count;

	count = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			while (needle[count] == (haystack[count]) && (needle[count]))
				count++;
			if (!needle[count])
				return ((char *)haystack);
		}
		haystack++;
		count = 0;
	}
	return (0);
}
