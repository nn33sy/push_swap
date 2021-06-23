/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhow-ch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 15:29:42 by inhow-ch          #+#    #+#             */
/*   Updated: 2020/09/13 14:03:41 by inhow-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		research_min(int *tab, int size)
{
	int count;
	int	min_value;
	int	i_min;

	count = 0;
	i_min = 0;
	min_value = tab[0];
	while (count < size)
	{
		if (tab[count] < min_value)
		{
			min_value = tab[count];
			i_min = count;
		}
		count++;
	}
	return (i_min);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	min;
	int	inter;

	if ((size != 1) && (size != 0))
	{
		min = research_min(tab, size);
		inter = tab[0];
		tab[0] = tab[min];
		tab[min] = inter;
		ft_sort_int_tab(&tab[1], size - 1);
	}
}
