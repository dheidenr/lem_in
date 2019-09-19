
#include "exdlst.h"

void	exdlstadd(t_exdlist **aexdlst, t_exdlist *new)
{
	if (aexdlst == NULL || new == NULL)
		return ;
	new->next = *aexdlst;
	(*aexdlst)->prev = new;
	new->start = new;
	new->end = (*aexdlst)->end;
	*aexdlst = new;
}
