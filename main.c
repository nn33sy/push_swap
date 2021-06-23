#include "pushswap.h"

int *ft_create_tab(t_list **stack, int len)
{
	t_list *tmp;
	int *tab;
	int i;

	tab = (int *)malloc(sizeof(int) * (len + 1));
	if (tab == NULL)
		return (NULL);
	tmp = *stack;
	i = 0;
	while (tmp != NULL)
	{
		tab[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	tab[i] = -1;
	return(tab);
}
void ft_print_tab(int *tab)
{
	int i;

	i = 0;
	while (tab[i] != -1)
	{
		printf(" %d ", tab[i]);
		i++;
	}
}

void ft_find_mediane(t_list **stack, int len)
{
	int *tab;
	int i_med;
	int med;

	tab = ft_create_tab(stack, len);
	ft_print_tab(tab);
	ft_sort_int_tab(tab, len);
	printf("\n");
	ft_print_tab(tab);
	i_med = len / 2;
	med = tab[i_med];
}

int	main(int argc, char **argv)
{
	if (ft_parsing(argc, argv) == -1)
		ft_error();
	ft_find_mediane(data.stack_a, data.len_a);
}
