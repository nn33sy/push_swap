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
void ft_sort(void)
{
    t_list *tmp;
    int i;

    tmp = *data.stack_b;
    data.min = tmp;
    data.max = tmp;
    i = 0;
    while (tmp != NULL)
    {
        if (tmp->content < data.min->content)
        {
            data.min = tmp;
            data.i_min = i;
        }
        if (tmp->content > data.max->content)
        {
            data.max = tmp;
            data.i_max = i;
        }
            i++;
        tmp = tmp->next;
    }
}

void ft_insert_min(void)
{
    if (data.len_b - data.i_min >= data.i_min)
        while (*data.stack_b != data.min)
        {
            data.i_max --;
            ft_rb();
        }
    else
        while (*data.stack_b != data.min)
        {
            data.i_max ++;
            ft_rrb();
        }
    ft_pa();
    data.i_max --;
    ft_ra();
    data.min = NULL;
}

void ft_insert_max()
{
    if (data.max == NULL)
        return ;

    if (data.len_b - data.i_max >= data.i_max)
     while (*data.stack_b != NULL && *data.stack_b != data.max)
            ft_rb();
    else
{
       while (*data.stack_b != NULL && *data.stack_b != data.max)
            ft_rrb();}
    ft_pa();
    data.max = NULL;
}

void ft_insert(void)
{
    while (data.len_b > 0)
       {
        ft_sort();
       ft_insert_min();
       ft_insert_max(); 
       }
}
void ft_putdown(int nb)
{
    int i;

    i = 0;
    while (i < nb / 2)
    {
        ft_ra();
        i++;
    }
}
void ft_make_stack_b(void)
{
    ft_find_mediane(data.stack_a, data.len_a);
    ft_debut_stacka(*(data.stack_a));
    ft_end_stacka();
    ft_mid_stack_a();
}
int ft_solve_one(void)
{

        data.nb_push = 0;
        ft_make_stack_b();
       data.len_b = data.nb_push;
      ft_insert();
        ft_putdown(data.nb_push);
       
       data.last_stackb = NULL;
        data.nb_push = 0;
        while ((*data.stack_a)->content >= data.med)
        {
            ft_pb();
            data.nb_push++;
        }
        data.len_b = data.nb_push;
        
        ft_insert();       
        while ((*data.stack_a)->content >data.med)
            ft_ra();
        
        data.last_stackb = NULL;
               ft_print_stack(data.stack_a);
return (1);
}
