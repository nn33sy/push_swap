#include "pushswap.h"

int ft_debut_stacka(t_list *tmp)
{
    t_list *next;

    next = tmp->next;
    if (tmp->content < data.med)
    {
        data.nb_push++;
        ft_pb();
        if (next != NULL)
            ft_debut_stacka(next);
    }
    return (1);
}

int ft_end_stacka()
{
    if (data.last_stacka->content < data.med)
    {
        data.nb_push++;
        ft_rra();
        ft_pb();
        if (data.last_stacka != NULL)
            ft_end_stacka();
    }
    return (1);
}

int ft_mid_stack_a()
{
     if (data.nb_push >= data.i_med)
        return (1);
    if ((*data.stack_a)->content >= data.med)
    {
        ft_ra();
        ft_mid_stack_a();
    }
    if ((*data.stack_a)->content < data.med)
    {
        data.nb_push ++;
        ft_pb();
        ft_mid_stack_a();
    }
    return (1);
}

int ft_solve_one(void)
{

    if  (data.len_a > 2)
    {
        data.nb_push = 0;
        ft_find_mediane(data.stack_a, data.len_a);
               ft_print_stack(data.stack_a);
       ft_print_stack(data.stack_b);
        printf("MED = %d i_MED = %d",data.med, data.i_med);
       ft_debut_stacka(*(data.stack_a));
       ft_end_stacka();
       ft_mid_stack_a();
       printf("\n \n"); 
       ft_solve_one();

    }
    if (data.len_a == 2)
    {
        if ((*data.stack_a)->content > (*data.stack_a)->next->content)
            ft_sa();
    }
    
return (1);
}
/*
int ft_solve_two(void)
{

}*/