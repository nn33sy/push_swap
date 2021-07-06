#include "pushswap.h"

char	*ft_parsing_double(char *line, double *nb)
{
	while (*line && ft_space(*line))
		line++;
	*nb = ft_atoi_ps(line);
	while (*line && ((*line >= '0' && *line <= '9')))
		line++;
	return (line);
}

void	ft_create_stack_abis(char *arg)
{
	double	nb;
	t_list	*tmp;

	data.len_a = 0;
	while (*arg != '\0')
	{
		arg = ft_parsing_double(arg, &nb);
		if (ft_check_duplicate(nb, data.stack_a) == -1)
			ft_error();
		tmp = ft_lstnew(nb);
		if (tmp == NULL)
			ft_error();
		ft_lstadd_back(data.stack_a, tmp);
		if (*arg == '\0')
			data.last_stacka = tmp;
		data.len_a++;
	}
}

void	ft_parsing_bis(char **arg)
{
	if (ft_initiate_data() == -1)
		ft_error();
	ft_create_stack_abis(arg[1]);
	data.last_stackb = NULL;
}
