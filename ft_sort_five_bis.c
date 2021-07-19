#include "pushswap.h"

void	ft_push_min(int strat)
{
	if (strat == 0 || strat == 1)
	{
		while (*g_da.stack_a != g_da.min)
			ft_ra();
	}
	if (strat == 2 || strat == 3)
	{
		while (*g_da.stack_a != g_da.min)
			ft_rra();
	}
	ft_pb();
}

void	ft_push_max(int strat)
{
	if (strat == 0 || strat == 2)
	{
		while (*g_da.stack_a != g_da.max)
			ft_ra();
	}
	if (strat == 1 || strat == 3)
	{
		while (*g_da.stack_a != g_da.max)
			ft_rra();
	}
	ft_pb();
}

void	ft_sort_five_bis(void)
{
	if ((*g_da.stack_b)->content < (*g_da.stack_b)->next->content)
	{
		ft_pa();
		ft_pa();
		ft_ra();
	}
	else
	{
		ft_pa();
		ft_ra();
		ft_pa();
	}
}

void	ft_sort_five(void)
{
	int	strat;
	int	first;

	ft_sort(g_da.stack_a);
	strat = ft_calculate(g_da.len_a, &first);
	if (first == 1)
	{
		ft_push_min(strat);
		ft_push_max(strat);
	}
	if (first == 2)
	{
		ft_push_max(strat);
		ft_push_min(strat);
	}
	ft_sort_three();
	ft_sort_five_bis();
}
