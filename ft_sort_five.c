#include "pushswap.h"

void ft_sort_two(void)
{
    if ((*g_da.stack_a)->content > (*g_da.stack_a)->next->content)
        ft_sa();
}

void ft_sort_three(void)
{
    int y1;
    int y2;
    int y3;

    y1 = (*g_da.stack_a)->content;
    y2 = (*g_da.stack_a)->next->content;
    y3 = (*g_da.stack_a)->next->next->content;
    if (y1 > y2 && y2 < y3 && y3 > y1)
        ft_sa();
    if (y1 > y2 && y2 > y3)
    {
        ft_sa();
        ft_rra();
    }
    if (y1 > y2 && y2 < y3 && y3 < y1)
        ft_ra();
    if (y1 < y2 && y2 > y3 && y3 > y1)
    {
        ft_sa();
        ft_ra();
    }
    if (y1 < y2 && y2 > y3 && y3 < y1)
        ft_rra();
}

int ft_max(int a, int b, int *first)
{
    if (a > b)
    {
        *first = 2;
        return (a);
    }
    *first = 1;
    return (b);
}
int ft_calculate(int len, int *first)
{
    int strat[4];
    int i;
    int min;
    int i_min;

    strat[0] = ft_max(g_da.i_min, g_da.i_max, first);
    strat[1] = (2 * g_da.i_min) + (len - g_da.i_max);
    strat[2] = (2 * (len - g_da.i_min)) + g_da.i_max;
    strat[3] = ft_max(len - g_da.i_min, len - g_da.i_max, first);
    min = strat[0];
    i_min = 0;
    i = 0;
    while (i < 4)
    {
        if (strat[i] < min)
        {
            min = strat[i];
            i_min = i;
        }
        i++;
    }
    if (i_min == 2 || i_min == 1)
        *first = 1;
    if (i_min == 0)
        ft_max(g_da.i_min, g_da.i_max, first);
    if (i_min == 3)
        ft_max(len - g_da.i_min, len - g_da.i_max, first);
    return (i_min);
}

void ft_push_min(int strat)
{
    if (strat == 0 || strat == 1)
    {
        while (*g_da.stack_a != g_da.min)
            ft_ra();
    }
    if (strat == 2 || strat == 3)
    {
        while (*g_da.stack_a != g_da.min)
            ft_rra();
    }
    ft_pb();
}

void ft_push_max(int strat)
{
    if (strat == 0 || strat == 2)
    {
        while (*g_da.stack_a != g_da.max)
            ft_ra();
    }
    if (strat == 1 || strat == 3)
    {
        while (*g_da.stack_a != g_da.max)
            ft_rra();
    }
    ft_pb();
}

void ft_sort_five(void)
{
    int strat;
    int first;

    ft_sort(g_da.stack_a);
    strat = ft_calculate(g_da.len_a, &first);
    if (first == 1)
    {
        ft_push_min(strat);
        ft_push_max(strat);
    }
    if (first == 2)
    {
        ft_push_max(strat);
        ft_push_min(strat);
    }
    ft_sort_three();
    if ((*g_da.stack_b)->content < (*g_da.stack_b)->next->content)
    {
        ft_pa();
        ft_pa();
        ft_ra();
    }
    else
    {
        ft_pa();
        ft_ra();
        ft_pa();
    }
}
