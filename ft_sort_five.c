#include "pushswap.h"

void	ft_sort_two(void)
{
	if ((*g_da.stack_a)->content > (*g_da.stack_a)->next->content)
		ft_sa();
}

void	ft_sort_three(void)
{
	int	y1;
	int	y2;
	int	y3;

	y1 = (*g_da.stack_a)->content;
	y2 = (*g_da.stack_a)->next->content;
	y3 = (*g_da.stack_a)->next->next->content;
	if (y1 > y2 && y2 < y3 && y3 > y1)
		ft_sa();
	if (y1 > y2 && y2 > y3)
	{
		ft_sa();
		ft_rra();
	}
	if (y1 > y2 && y2 < y3 && y3 < y1)
		ft_ra();
	if (y1 < y2 && y2 > y3 && y3 > y1)
	{
		ft_sa();
		ft_ra();
	}
	if (y1 < y2 && y2 > y3 && y3 < y1)
		ft_rra();
}

int	ft_max(int a, int b, int *first)
{
	if (a > b)
	{
		*first = 2;
		return (a);
	}
	*first = 1;
	return (b);
}

void	ft_calculate_bis(int len, int *first, int i_min)
{
	if (i_min == 2 || i_min == 1)
		*first = 1;
	if (i_min == 0)
		ft_max(g_da.i_min, g_da.i_max, first);
	if (i_min == 3)
		ft_max(len - g_da.i_min, len - g_da.i_max, first);
}

int	ft_calculate(int len, int *first)
{
	int	strat[4];
	int	i;
	int	min;
	int	i_min;

	strat[0] = ft_max(g_da.i_min, g_da.i_max, first);
	strat[1] = (2 * g_da.i_min) + (len - g_da.i_max);
	strat[2] = (2 * (len - g_da.i_min)) + g_da.i_max;
	strat[3] = ft_max(len - g_da.i_min, len - g_da.i_max, first);
	min = strat[0];
	i_min = 0;
	i = 0;
	while (i < 4)
	{
		if (strat[i] < min)
		{
			min = strat[i];
			i_min = i;
		}
		i++;
	}
	ft_calculate_bis(len, first, i_min);
	return (i_min);
}
