/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   future_libft_addone_two.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:55:14 by dheidenr          #+#    #+#             */
/*   Updated: 2019/06/20 13:55:20 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_exit(const char *str)
{
	if (!str)
		return ;
	write(2, str, ft_strlen(str));
	exit(0);
}

void	*void_free(void *void_free, void *value)
{
	free(void_free);
	void_free = NULL;
	return (value);
}

void	*dlst_free(t_dlist *dlist_free, void *value)
{
	ft_dlstdel(&dlist_free, memsetdel);
	return (value);
}

char	*malloc_str(char *str)
{
	str = strjoin_free(ft_memalloc(1), str, 1);
	return (str);
}
