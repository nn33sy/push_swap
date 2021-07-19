#include "pushswap.h"

void	ft_sort(t_list **stack)
{
	t_list	*tmp;
	int		i;

	tmp = *stack;
	g_da.min = tmp;
	g_da.i_min = 0;
	g_da.i_max = 0;
	g_da.max = tmp;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->content < g_da.min->content)
		{
			g_da.min = tmp;
			g_da.i_min = i;
		}
		if (tmp->content > g_da.max->content)
		{
			g_da.max = tmp;
			g_da.i_max = i;
		}
		i++;
		tmp = tmp->next;
	}
}

void	ft_insert_min(void)
{
	if (g_da.len_b - g_da.i_min >= g_da.i_min)
	{
		while (*g_da.stack_b != g_da.min)
		{
			g_da.i_max --;
			ft_rb();
		}
	}
	else
	{
		while (*g_da.stack_b != g_da.min)
		{
			g_da.i_max ++;
			ft_rrb();
		}
	}
	ft_pa();
	g_da.i_max --;
	ft_ra();
	g_da.min = NULL;
}

void	ft_insert_max(void)
{
	if (g_da.max == NULL)
		return ;
	if (g_da.len_b - g_da.i_max >= g_da.i_max)
		while (*g_da.stack_b != NULL && *g_da.stack_b != g_da.max)
			ft_rb();
	else
		while (*g_da.stack_b != NULL && *g_da.stack_b != g_da.max)
			ft_rrb();
	ft_pa();
	g_da.max = NULL;
}

void	ft_insert(void)
{
	while (g_da.len_b > 0)
	{
		if (g_da.len_b == 1)
			ft_pa();
		ft_sort(g_da.stack_b);
		ft_insert_min();
		ft_insert_max();
	}
}
