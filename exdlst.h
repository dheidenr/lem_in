/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exdlst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:05:01 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/21 13:05:04 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXDLIST_H
#define EXDLIST_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_exdlist
{
	void			*content;
	size_t			content_size;
	struct s_exdlist	*next;
	struct s_exdlist	*prev;
	struct s_exdlist	*start;
	struct s_exdlist	*end;
}					t_exdlist;

t_exdlist	*exdlstnew(void const *content, size_t content_size);
void			exdlstdel(t_exdlist **adlst, void (*del)(void *, size_t));
void			memsetdel(void *entity, size_t size);
void			exdlstadd(t_exdlist **aexdlst, t_exdlist *new);
void			exdlist_int_put(t_exdlist *exdlist);
size_t			exdlistlen(t_exdlist *stack);
t_exdlist		*exdlstdub_int(t_exdlist *stack);

#endif
