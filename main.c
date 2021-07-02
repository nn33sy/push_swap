#include "pushswap.h"


int	main(int argc, char **argv)
{
	if (ft_parsing(argc, argv) == -1)
		ft_error();
ft_print_stack(data.stack_a);
        ft_print_reverse(data.last_stacka);
		printf("\n");
	ft_rra();
	ft_print_stack(data.stack_a);
     ft_print_reverse(data.last_stacka);
	//ft_solve_one();
	//ft_find_mediane(data.stack_a, data.len_a);
}
