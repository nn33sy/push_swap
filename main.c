#include "pushswap.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_parsing_bis(argv);
	else
		ft_parsing(argc, argv);
	g_da.list_med = (t_list **)malloc(sizeof(t_list *));
	if (g_da.list_med == NULL)
		ft_error();
	if (g_da.len_a == 1)
		return (0);
	if (g_da.len_a == 2)
	{
		ft_sort_two();
		return(0);
	}
	if (g_da.len_a == 3)
	{
		ft_sort_three();
		return(0);
	}
	if (g_da.len_a == 5)
	{
		ft_sort_five();
		return(0);
	}
	if (g_da.len_a <= 100)
		ft_solve_hundred();
	if (g_da.len_a > 100)
		ft_solve_five_hundred();
}
