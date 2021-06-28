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
        *(data.stack_a) = tmp;
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
            *(data.stack_a) = tmp->next;
        else 
            *(data.stack_a) = NULL;
        tmp->next = *(data.stack_b);
        *(data.stack_b) = tmp;
        return (1);
    }
    return (-1);

}