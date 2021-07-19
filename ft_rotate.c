#include "pushswap.h"

t_list	*ft_last(t_list **stack)
{
	t_list	*last;

	last = *(stack);
	if (last == NULL)
		return (NULL);
	while (last->next != NULL)
		last = last->next;
	return (last);
}

int	ft_ra(void)
{
	t_list	*tmp;

	if (*(g_da.stack_a) != NULL)
	{
		ft_putstr_fd("ra\n", 1);
		if ((*g_da.stack_a)->next != NULL)
		{
			tmp = *(g_da.stack_a);
			*(g_da.stack_a) = tmp->next;
			(*g_da.stack_a)->before = NULL;
			g_da.last_stacka->next = tmp;
			tmp->before = g_da.last_stacka;
			tmp->next = NULL;
			g_da.last_stacka = tmp;
			return (1);
		}
		else
			g_da.last_stacka = (*g_da.stack_a);
	}
	else
		g_da.last_stacka = NULL;
	return (-1);
}

int	ft_rb(void)
{
	t_list	*tmp;

	if (*(g_da.stack_b) != NULL)
	{
		ft_putstr_fd("rb\n", 1);
		if ((*g_da.stack_b)->next != NULL)
		{
			tmp = *(g_da.stack_b);
			*(g_da.stack_b) = tmp->next;
			(*g_da.stack_b)->before = NULL;
			g_da.last_stackb->next = tmp;
			tmp->before = g_da.last_stackb;
			tmp->next = NULL;
			g_da.last_stackb = tmp;
			return (1);
		}
		else
			g_da.last_stackb = (*g_da.stack_b);
	}
	else
		g_da.last_stackb = NULL;
	return (-1);
}

int	ft_rr(void)
{
	if (ft_ra() == -1 && ft_rb() == -1)
		return (-1);
	return (1);
}
