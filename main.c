#include "pushswap.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_parsing_bis(argv);
	}else 
		ft_parsing(argc, argv);
	data.list_med = (t_list **)malloc(sizeof(t_list *));
	if (data.list_med == NULL)
		ft_error();
	if (data.len_a == 1)	
		return(0);
	//if (data.len_a <= 100)	
	//	ft_solve_hundred();

	//if (data.len_a > 100 && data.len_a <= 501)	
		ft_solve_five_hundredbis();

}
