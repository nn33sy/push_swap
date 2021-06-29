#include "pushswap.h"

int	ft_initiate_data(void)
{
	data.stack_a = (t_list **)malloc(sizeof(t_list *));
	if (data.stack_a == NULL)
		return (-1);
	*data.stack_a = NULL;
	data.stack_b = (t_list **)malloc(sizeof(t_list *));
	data.len_b = 0;
	if (data.stack_b == NULL)
		return (-1);
	*data.stack_b = NULL;
	return (1);
}

int	ft_check_duplicate(int nb, t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		if (nb == tmp->content)
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_create_stack_a(int len, char **arg)
{
	int		i;
	t_list	*tmp;
	int		nb;

	i = 1;
	while (i < len)
	{
		if (ft_isnb(arg[i]) == 0)
			ft_error();
		nb = ft_atoi(arg[i]);
		if (ft_check_duplicate(nb, data.stack_a) == -1)
			ft_error();
		tmp = ft_lstnew(nb);
		if (tmp == NULL)
			ft_error();
		ft_lstadd_back(data.stack_a, tmp);
		if (i == len - 1)
			data.last_stacka = tmp;
		i++;
	}
	data.len_a = len - 1;
	return (1);
}

int	ft_parsing(int len, char **arg)
{
	if (ft_initiate_data() == -1)
		ft_error();
	ft_create_stack_a(len, arg);
	data.last_stackb = NULL;


	return (1);
}