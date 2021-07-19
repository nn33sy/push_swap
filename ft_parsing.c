#include "pushswap.h"

int	ft_initiate_data(void)
{
	g_da.stack_a = (t_list **)malloc(sizeof(t_list *));
	if (g_da.stack_a == NULL)
		return (-1);
	*g_da.stack_a = NULL;
	g_da.stack_b = (t_list **)malloc(sizeof(t_list *));
	g_da.len_b = 0;
	if (g_da.stack_b == NULL)
		return (-1);
	*g_da.stack_b = NULL;
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
		if (ft_check_duplicate(nb, g_da.stack_a) == -1)
			ft_error();
		tmp = ft_lstnew(nb);
		if (tmp == NULL)
			ft_error();
		ft_lstadd_back(g_da.stack_a, tmp);
		if (i == len - 1)
			g_da.last_stacka = tmp;
		i++;
	}
	g_da.len_a = len - 1;
	return (1);
}

int	ft_parsing(int len, char **arg)
{
	if (ft_initiate_data() == -1)
		ft_error();
	ft_create_stack_a(len, arg);
	g_da.last_stackb = NULL;
	return (1);
}
