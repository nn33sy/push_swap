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

	if (data.stack_b != NULL && *(data.stack_b) != NULL)
	{
		printf("pa\n");
		tmp = *(data.stack_b);
		ft_update_push(tmp, data.stack_b);
		tmp->next = *(data.stack_a);
		tmp->before = NULL;
		if (*(data.stack_a) != NULL)
			(*data.stack_a)->before = tmp;
		if (data.last_stacka == NULL)
			data.last_stacka = tmp;
		*(data.stack_a) = tmp;
		data.len_a++;
		data.len_b--;
		return (1);
	}
	return (-1);
}

int	ft_pb(void)
{
	t_list	*tmp;

	if (data.stack_a != NULL && *(data.stack_a) != NULL)
	{
		printf("pb\n");
		tmp = *(data.stack_a);
		ft_update_push(tmp, data.stack_a);
		tmp->next = *(data.stack_b);
		tmp->before = NULL;
		if (*(data.stack_b) != NULL)
			(*data.stack_b)->before = tmp;
		if (data.last_stackb == NULL)
			data.last_stackb = tmp;
		*(data.stack_b) = tmp;
		data.len_b++;
		data.len_a--;
		return (1);
	}
	return (-1);
}
