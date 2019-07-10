#include "libft.h"
#include "exdlst.h"

void	exdlist_int_put_in_cycle(t_exdlist *exdlist)
{
	ft_putstr("dlist_content:|");
	ft_putnbr(*(int *)exdlist->content);
	ft_putstr("| ");
	if (exdlist->next)
	{
		ft_putstr("dlist->next:|Yes  ");
		ft_putnbr(*(int *)exdlist->next->content);
		ft_putchar('|');
	}
	else
		ft_putstr("dlist->next:|Null| ");
	if (exdlist->prev)
	{
		ft_putstr("dlist->prev:|Yes  ");
		ft_putnbr(*(int *)exdlist->prev->content);
		ft_putchar('|');
	}
	else
		ft_putstr("dlist->prev:|Null| ");
}

void	exdlist_int_put(t_exdlist *exdlist)
{
//	ft_putchar('\n');
//	ft_putstr(__func__);
//	ft_putstr("\nstep of next->\n");
	if (!exdlist)
		ft_putstr("NULL\n");
	while (exdlist)
	{
		exdlist_int_put_in_cycle(exdlist);
		exdlist = exdlist->next;
		ft_putstr("\n");
	}
}
