#include "pushswap.h"

void	ft_error(void)
{
	printf("Error\n");
	exit(EXIT_FAILURE);
}

void	ft_print_stack(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d", tmp->content);
		tmp = tmp->next;
	}
}

