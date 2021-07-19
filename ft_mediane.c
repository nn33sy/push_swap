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

void	ft_med_seven(int len, int *tab)
{
	g_da.med.i_one = len / 8;
	g_da.med.i_two = len / 4;
	g_da.med.i_three = (3 * len) / 8;
	g_da.med.i_four = len / 2;
	g_da.med.i_five = (5 * len) / 8;
	g_da.med.i_six = (3 * len) / 4;
	g_da.med.i_seven = (7 * len) / 8;
	g_da.med.one = tab[g_da.med.i_one];
	g_da.med.two = tab[g_da.med.i_two];
	g_da.med.three = tab[g_da.med.i_three];
	g_da.med.four = tab[g_da.med.i_four];
	g_da.med.five = tab[g_da.med.i_five];
	g_da.med.six = tab[g_da.med.i_six];
	g_da.med.seven = tab[g_da.med.i_seven];
}

void	ft_find_mediane(t_list **stack, int len)
{
	int	*tab;
	int	tri;

	tri = 1;
	tab = ft_create_tab(stack, len);
	ft_sort_int_tab(tab, len, &tri);
	if (tri == 1)
		exit(EXIT_FAILURE);
	free(tab);
	if (g_da.len_a <= 100)
	{
		g_da.med.i_one = len / 2;
		g_da.med.one = tab[g_da.med.i_one];
	}
	if (g_da.len_a > 100)
		ft_med_seven(g_da.len_a, tab);
}
