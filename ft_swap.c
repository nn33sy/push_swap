#include "pushswap.h"

int ft_sa(void)
{
    int tmp;


    if (data.stack_a != NULL && (*(data.stack_a)) != NULL && ((*(data.stack_a))->next) != NULL)
        {
            printf("sa\n");
            tmp = (*data.stack_a)->content;
            (*data.stack_a)->content = (*data.stack_a)->next->content;
            (*data.stack_a)->next->content = tmp;
            return (1);
        }
    return (-1);
}

int ft_sb(void)
{
    int tmp;

    if (data.stack_b != NULL && (*(data.stack_b)) != NULL && ((*(data.stack_b))->next) != NULL)
        {
            printf("sb\n");
            tmp = (*data.stack_b)->content;
            (*data.stack_b)->content = (*data.stack_b)->next->content;
            (*data.stack_b)->next->content = tmp;
            return (1);
        }
    return (-1);
}

int ft_ss(void)
{
    if (ft_sa() == -1 && ft_sb() == -1)
        return (-1);
    return (1);
}