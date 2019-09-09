
#include "lem_in.h"

void	output(t_beam *beam, t_context *context)
{
	//ants_i = (M + L)/P - l_i
	//Количество муравьев по конкретному пути равно сумме всего муравьев плюс сумму длин путей (в шагах)
	//поделенное на P - количество путей и минус длинна в шагах текущего пути.

	//Подготовака к выводу:
	//Функция которая получает сумму всех длин путей пучка сохранить в переменную.

	//Функция которая сохраняет число муравьев которых надо пустить по каждому пути в ants
	prepare_beam_ants(context->global_ants, beam);

	//Функция которая получает число путей из beam
	//Функция которая отправляет одного муравья по пути с выводом шага
	ants_go_the_paths(beam, context);
	//Функия которая отправляет муравьев по путям с выводом этих путей и переходом на новую строку
}