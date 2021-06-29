#include "pushswap.h"

t_list *ft_last_before(t_list **stack)
{
    t_list *tmp;
    t_list *lst;


    tmp = *(stack);
    while (tmp->next->next != NULL)
        tmp = tmp->next;   
    lst = tmp->next;
    tmp->next = NULL;
    return (lst);
}

int ft_rra(void)
{
    t_list *tmp;

    if (data.stack_a != NULL && *(data.stack_a) != NULL
    && (*data.stack_a)->next != NULL)
    {      
    if ((*data.stack_a)->next->next == NULL)
        {
            ft_sa();
            return (1);
        }
        tmp = data.last_stacka;
        data.last_stacka = data.last_stacka->before;
            if (data.len_a <= 6)
            return (1);
        data.last_stacka->next = NULL;
              
        tmp->next = *(data.stack_a);
        *(data.stack_a) = tmp;
        return (1);
    }
    return (-1);
}


int ft_rrb(void)
{
    t_list *tmp;

    if (data.stack_b != NULL && *(data.stack_b) != NULL
    && (*data.stack_b)->next != NULL)
    {
    if ((*data.stack_b)->next->next == NULL)
        {
            ft_sb();
            return (1);
        }
        tmp = data.last_stackb;
        data.last_stackb = data.last_stackb->before;
        tmp->before->next = NULL;
        tmp->next = *(data.stack_b);
        *(data.stack_b) = tmp;
        return (1);
    }
    return (-1);
}

int ft_rrr(void)
{
    if (ft_rra() == -1 && ft_rrb() == -1)
        return (-1);
    return (1);
}