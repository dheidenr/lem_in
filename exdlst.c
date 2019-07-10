#include "libft.h"
#include "exdlst.h"

void	exdlist_int_put(t_exdlist *exdlist)
{
	ft_putchar('\n');
	ft_putstr(__func__);
	ft_putstr("\nstep of next->\n");
	while (exdlist)
	{
		dlist_int_put_in_cycle(exdlist);
		exdlist = exdlist->next;
		ft_putstr("\n");
	}
}
