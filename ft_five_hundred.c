#include "pushswap.h"

void	ft_sep(t_list **stack, int i_lim, int val_sup)
{
	int	i;

	i = 0;
	while (i < i_lim)
	{
		if (((*stack)->content) >= val_sup)
		{
			ft_pa();
			i++;
		}
		else
			ft_rb();
	}
}

void	ft_sepbis(t_list **stack, int i_lim, int val_sup)
{
	int	i;

	i = 0;
	while (i < i_lim)
	{
		if (((*stack)->content) >= val_sup)
			ft_pa();
		else
		{
			i++;
			ft_rb();
		}
	}
}

void	ft_solve_five_hundredbis(void)
{
	while (((*g_da.stack_a)->content) >= g_da.med.four)
		ft_pb();
	g_da.len_b = ft_lstsize(*g_da.stack_b);
	ft_sepbis(g_da.stack_b, g_da.med.i_six - g_da.med.i_four, g_da.med.six);
	ft_sepbis(g_da.stack_b, g_da.med.i_five - g_da.med.i_four, g_da.med.five);
	ft_insert();
	ft_putdown(g_da.med.five);
	g_da.last_stackb = NULL;
	while (((*g_da.stack_a)->content) < g_da.med.six)
		ft_pb();
	ft_insert();
	ft_putdown(g_da.med.six);
	g_da.last_stackb = NULL;
	while (((*g_da.stack_a)->content) >= g_da.med.six)
		ft_pb();
	g_da.len_b = ft_lstsize(*g_da.stack_b);
	ft_sepbis(g_da.stack_b, g_da.med.i_seven - g_da.med.i_six, g_da.med.seven);
	ft_insert();
	ft_putdown(g_da.med.seven);
	g_da.last_stackb = NULL;
	while (((*g_da.stack_a)->content) >= g_da.med.seven)
		ft_pb();
	ft_insert();
	while (((*g_da.stack_a)->content) >= g_da.med.seven)
		ft_ra();
}

void	ft_solve_five_hundred(void)
{
	ft_find_mediane(g_da.stack_a, g_da.len_a);
	ft_make_stack_b(g_da.med.four, g_da.med.i_four);
	ft_sep(g_da.stack_b, g_da.med.i_four - g_da.med.i_two, g_da.med.two);
	ft_sep(g_da.stack_b, g_da.med.i_two - g_da.med.i_one, g_da.med.one);
	ft_insert();
	ft_putdown(g_da.med.one);
	g_da.last_stackb = NULL;
	while (((*g_da.stack_a)->content) < g_da.med.two)
		ft_pb();
	ft_insert();
	ft_putdown(g_da.med.two);
	g_da.last_stackb = NULL;
	while (((*g_da.stack_a)->content) < g_da.med.four)
		ft_pb();
	ft_sep(g_da.stack_b, g_da.med.i_four - g_da.med.i_three, g_da.med.three);
	ft_insert();
	ft_putdown(g_da.med.three);
	 g_da.len_b = ft_lstsize(*g_da.stack_b);
	g_da.last_stackb = NULL;
	while (((*g_da.stack_a)->content) < g_da.med.four)
		ft_pb();
	ft_insert();
	ft_putdown(g_da.med.four);
	g_da.last_stackb = NULL;
	ft_solve_five_hundredbis();
}
