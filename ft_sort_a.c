#include "pushswap.h"

int	ft_debut_stacka(t_list *tmp, int med)
{
	t_list	*next;

	next = tmp->next;
	if (tmp->content < med)
	{
		g_da.nb_push++;
		ft_pb();
		if (next != NULL)
			ft_debut_stacka(next, med);
	}
	return (1);
}

int	ft_end_stacka(int med)
{
	if (g_da.last_stacka->content < med)
	{
		g_da.nb_push++;
		ft_rra();
		ft_pb();
		if (g_da.last_stacka != NULL)
			ft_end_stacka(med);
	}
	return (1);
}

int	ft_mid_stack_a(int med, int i_med)
{
	 if (g_da.nb_push >= i_med)
		return (1);
	if ((*g_da.stack_a)->content >= med)
	{
		ft_ra();
		ft_mid_stack_a(med, i_med);
	}
	if ((*g_da.stack_a)->content < med)
	{
		g_da.nb_push ++;
		ft_pb();
		ft_mid_stack_a(med, i_med);
	}
	return (1);
}
