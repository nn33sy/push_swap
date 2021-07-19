#include "pushswap.h"

void	ft_putdown(int med)
{
	while ((*g_da.stack_a)->content < med)
		ft_ra();
}

void	ft_make_stack_b(int med, int i)
{
	ft_debut_stacka(*(g_da.stack_a), med);
	ft_end_stacka(med);
	ft_mid_stack_a(med, i);
}

int	ft_solve_hundred(void)
{
	g_da.nb_push = 0;
	ft_find_mediane(g_da.stack_a, g_da.len_a);
	ft_make_stack_b(g_da.med.one, g_da.med.i_one);
	g_da.len_b = g_da.nb_push;
	ft_insert();
	ft_putdown(g_da.med.one);
	g_da.last_stackb = NULL;
	g_da.nb_push = 0;
	while ((*g_da.stack_a)->content >= g_da.med.one)
	{
		ft_pb();
		g_da.nb_push++;
	}
	g_da.len_b = g_da.nb_push;
	ft_insert();
	while ((*g_da.stack_a)->content > g_da.med.one)
		ft_ra();
	g_da.last_stackb = NULL;
	return (1);
}
