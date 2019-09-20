
#include "lem_in.h"

/*
** ants_i = (M + L)/P - l_i
** Количество муравьев по конкретному пути равно сумме всего муравьев плюс
** сумму длин путей (в шагах)
** поделенное на P - количество путей и минус длинна в шагах текущего пути.
** prepare_beam_ants - Функция которая сохраняет число муравьев которых надо
** пустить по каждому пути в ants
** ants_go_the_paths - Функция которая отправляет муравьев по путям с выводом
** этих путей и переходом на новую строку
*/
void	output(t_beam *beam, t_context *context)
{
	prepare_beam_ants(context->global_ants, beam);
	if (context->debug)
	{
		ft_putstr("final beam:\n");
		print_beam(beam);
	}
	ants_go_the_paths(beam, context);
}
