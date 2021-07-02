#include "pushswap.h"


int	main(int argc, char **argv)
{
	if (ft_parsing(argc, argv) == -1)
		ft_error();
	ft_solve_one();
	//ft_find_mediane(data.stack_a, data.len_a);
}
