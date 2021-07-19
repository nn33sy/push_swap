#include "pushswap.h"

t_list	*ft_last_before(t_list **stack)
{
	t_list	*tmp;
	t_list	*lst;

	tmp = *(stack);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	lst = tmp->next;
	tmp->next = NULL;
	return (lst);
}

int	ft_rra(void)
{
	t_list	*tmp;

	if (g_da.stack_a != NULL && *(g_da.stack_a) != NULL
		&& (*g_da.stack_a)->next != NULL)
	{
		if ((*g_da.stack_a)->next->next == NULL)
		{
			ft_sa();
			return (1);
		}
		ft_putstr_fd("rra\n", 1);
		tmp = g_da.last_stacka;
		g_da.last_stacka = g_da.last_stacka->before;
		g_da.last_stacka->next = NULL;
		tmp->next = *(g_da.stack_a);
		tmp->before = NULL;
		(*g_da.stack_a)->before = tmp;
		*(g_da.stack_a) = tmp;
		return (1);
	}
	return (-1);
}

int	ft_rrb(void)
{
	t_list	*tmp;

	if (g_da.stack_b != NULL && *(g_da.stack_b) != NULL
		&& (*g_da.stack_b)->next != NULL)
	{
		if ((*g_da.stack_b)->next->next == NULL)
		{
			ft_sb();
			return (1);
		}
		ft_putstr_fd("rrb\n", 1);
		tmp = g_da.last_stackb;
		g_da.last_stackb = g_da.last_stackb->before;
		g_da.last_stackb->next = NULL;
		tmp->next = *(g_da.stack_b);
		tmp->before = NULL;
		(*g_da.stack_b)->before = tmp;
		*(g_da.stack_b) = tmp;
		return (1);
	}
	return (-1);
}

int	ft_rrr(void)
{
	if (ft_rra() == -1 && ft_rrb() == -1)
		return (-1);
	return (1);
}
