#include "pushswap.h"

int ft_pa()
{
    t_list *tmp;

    if (data.stack_b != NULL && *(data.stack_b) != NULL)
    {
        tmp = *(data.stack_b);
        if (tmp->next != NULL)
            *(data.stack_b) = tmp->next;
        else 
            *(data.stack_b) = NULL;
        tmp->next = *(data.stack_a);
        if (data.last_stacka == NULL)
            data.last_stacka = tmp;
        *(data.stack_a) = tmp;
        data.len_b--;
        data.len_a++;
        return (1);
    }
    return (-1);

}

int ft_pb()
{
    t_list *tmp;

    if (data.stack_a != NULL && *(data.stack_a) != NULL)
    {
        tmp = *(data.stack_a);
        if (tmp->next != NULL)
        {
            *(data.stack_a) = tmp->next;
            tmp->next->before = NULL;
        }
        else 
            *(data.stack_a) = NULL;
        tmp->next = *(data.stack_b);
        tmp->before = NULL;
        if (data.last_stackb == NULL)
            data.last_stackb = tmp;
        *(data.stack_b) = tmp;
        data.len_b++;
        data.len_a--;
        return (1);
    }
    return (-1);

}