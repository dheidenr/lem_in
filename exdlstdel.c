
#include "exdlst.h"

void	exdlstdel(t_exdlist **aexdlist, void (*del)(void *, size_t))
{
	t_exdlist *next_exlst;

	if (*aexdlist == NULL || !aexdlist || !del)
		return ;
	while (*aexdlist)
	{
		next_exlst = (*aexdlist)->next;
		del((*aexdlist)->content, (*aexdlist)->content_size);
		free((*aexdlist));
		*aexdlist = NULL;
		(*aexdlist)->start = NULL;
		(*aexdlist)->end = NULL;
		*aexdlist = next_exlst;
	}
	*aexdlist = NULL;
}