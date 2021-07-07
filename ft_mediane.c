#include "pushswap.h"

int	*ft_create_tab(t_list **stack, int len)
{
	t_list	*tmp;
	int		*tab;
	int		i;

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
	return (tab);
}

void	ft_print_tab(int *tab)
{
	int	i;

	i = 0;
	while (tab[i] != -1)
	{
		printf(" %d ", tab[i]);
		i++;
	}
}

void	ft_find_mediane(t_list **stack, int len)
{
	int	*tab;

	tab = ft_create_tab(stack, len);
	ft_sort_int_tab(tab, len);
	free(tab);
	//if (data.len_a <= 100)
	//{
	//	data.med.i_one = len / 2;
	//	data.med.one = tab[data.med.i_one];
//	}
//	else
//	{
		data.med.i_one = len / 8;
		data.med.i_two = len / 4;
		data.med.i_three = (3 * len) / 8;
		data.med.i_four = len / 2;
		data.med.i_five = (5 * len) / 8;
		data.med.i_six = (3 * len) / 4;
		data.med.i_seven  = (7 * len) / 8;
		data.med.one = tab[data.med.i_one];
		data.med.two = tab[data.med.i_two];
		data.med.three = tab[data.med.i_three];
		data.med.four = tab[data.med.i_four];
		data.med.five = tab[data.med.i_five];
		data.med.six = tab[data.med.i_six];
		data.med.seven = tab[data.med.i_seven];
	//	printf("MED %d %d %d %d %d %d %d\n",data.med.one, data.med.two, data.med.three,data.med.four, data.med.five, data.med.six,data.med.seven);
//	}	
}
