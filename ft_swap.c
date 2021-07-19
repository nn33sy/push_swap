#include "pushswap.h"

int	ft_sa(void)
{
	int	tmp;

	if (g_da.stack_a != NULL && (*(g_da.stack_a)) != NULL
		&& ((*(g_da.stack_a))->next) != NULL)
	{
		ft_putstr_fd("sa\n", 1);
		tmp = (*g_da.stack_a)->content;
		(*g_da.stack_a)->content = (*g_da.stack_a)->next->content;
		(*g_da.stack_a)->next->content = tmp;
		return (1);
	}
	return (-1);
}

int	ft_sb(void)
{
	int	tmp;

	if (g_da.stack_b != NULL && (*(g_da.stack_b)) != NULL
		&& ((*(g_da.stack_b))->next) != NULL)
	{
		ft_putstr_fd("sb\n", 1);
		tmp = (*g_da.stack_b)->content;
		(*g_da.stack_b)->content = (*g_da.stack_b)->next->content;
		(*g_da.stack_b)->next->content = tmp;
		return (1);
	}
	return (-1);
}

int	ft_ss(void)
{
	if (ft_sa() == -1 && ft_sb() == -1)
		return (-1);
	return (1);
}
