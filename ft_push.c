#include "pushswap.h"

void	ft_update_push(t_list *tmp, t_list **stack)
{
	if (tmp->next != NULL)
	{
		*(stack) = tmp->next;
		tmp->next->before = NULL;
	}
	else
		*(stack) = NULL;
}

int	ft_pa(void)
{
	t_list	*tmp;

	if (g_da.stack_b != NULL && *(g_da.stack_b) != NULL)
	{
		ft_putstr_fd("pa\n", 1);
		tmp = *(g_da.stack_b);
		ft_update_push(tmp, g_da.stack_b);
		tmp->next = *(g_da.stack_a);
		tmp->before = NULL;
		if (*(g_da.stack_a) != NULL)
			(*g_da.stack_a)->before = tmp;
		if (g_da.last_stacka == NULL)
			g_da.last_stacka = tmp;
		*(g_da.stack_a) = tmp;
		g_da.len_a++;
		g_da.len_b--;
		return (1);
	}
	return (-1);
}

int	ft_pb(void)
{
	t_list	*tmp;

	if (g_da.stack_a != NULL && *(g_da.stack_a) != NULL)
	{
		ft_putstr_fd("pb\n", 1);
		tmp = *(g_da.stack_a);
		ft_update_push(tmp, g_da.stack_a);
		tmp->next = *(g_da.stack_b);
		tmp->before = NULL;
		if (*(g_da.stack_b) != NULL)
			(*g_da.stack_b)->before = tmp;
		if (g_da.last_stackb == NULL)
			g_da.last_stackb = tmp;
		*(g_da.stack_b) = tmp;
		g_da.len_b++;
		g_da.len_a--;
		return (1);
	}
	return (-1);
}
