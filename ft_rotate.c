#include "pushswap.h"

t_list *ft_last(t_list **stack)
{
    t_list *last;

    last = *(stack);
    if (last == NULL)
        return (NULL);
    while (last->next != NULL)
        last = last->next;
    return (last);
}

int ft_ra(void)
{
        t_list *tmp;

        if (*(data.stack_a) != NULL)
        {
            if ((*data.stack_a)->next != NULL)
            {
            tmp = *(data.stack_a);
            *(data.stack_a) = tmp->next;
            (*data.stack_a)->before = NULL;
            tmp->next = data.last_stacka;
            tmp->before = NULL;
            data.last_stacka->next = tmp;
            data.last_stacka = tmp;
            return (1);
            }
            else 
                data.last_stacka = (*data.stack_a);

        }
        else
            data.last_stacka = NULL;
        return (-1);
}

int ft_rb(void)
{
        t_list *tmp;

        if (*(data.stack_b) != NULL)
        {
            if ((*data.stack_b)->next != NULL)
            {
            tmp = *(data.stack_b);
            *(data.stack_b) = tmp->next;
            tmp->next->before = NULL;
            tmp->next = NULL;
            data.last_stackb->next = tmp;
            data.last_stackb = tmp;
            return (1);
            }
            else 
                data.last_stackb = (*data.stack_b);

        }
        else 
            data.last_stackb = NULL;

        return (-1);
}

int ft_rr(void)
{
    if (ft_ra() == -1 && ft_rb() == -1)
        return (-1);
    return (1);
}