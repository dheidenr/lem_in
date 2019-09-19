
#include "exdlst.h"

size_t	exdlistlen(t_exdlist *stack)
{
	size_t	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
