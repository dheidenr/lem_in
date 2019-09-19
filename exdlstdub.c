
#include "exdlst.h"

t_exdlist	*exdlstdub_int(t_exdlist *stack)
{
	t_exdlist	*temp;
	t_exdlist	*exdlst;

	exdlst = stack;
	if (!stack)
		return (NULL);
	while (exdlst->next)
		exdlst = exdlst->next;
	temp = NULL;
	while (exdlst)
	{
		if (!exdlst->next)
			temp = exdlstnew((int *)exdlst->content,
							  sizeof(*(int *)exdlst->content));
		else
			exdlstadd(&temp, exdlstnew((int *)exdlst->content,
										 sizeof(*(int *)exdlst->content)));
		exdlst = exdlst->prev;
	}
	return (temp);
}
