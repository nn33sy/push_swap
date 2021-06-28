#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stacks
{
    t_list **stack_a;
    int     len_a;
    t_list **stack_b;
    int     len_b;
}t_stacks;

t_stacks data;

int	ft_initiate_data(void);
int	ft_check_duplicate(int nb, t_list **stack);
int	ft_create_stack_a(int len, char **arg);
int	ft_parsing(int len, char **arg);
void	ft_print_stack(t_list **stack);
void	ft_error(void);
void	ft_sort_int_tab(int *tab, int size);
int ft_sa(void);
int ft_sb(void);
int ft_pa(void);
int ft_pb(void);
int ft_ra(void);
int ft_rb(void);
int ft_rr(void);
t_list *ft_last(t_list **stack);
t_list *ft_last_before(t_list **stack);
int ft_rra(void);
int ft_rrb(void);
int ft_rrr(void);
#endif