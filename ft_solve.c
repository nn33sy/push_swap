#include "pushswap.h"

int ft_debut_stacka(t_list *tmp, int med)
{
    t_list *next;

    next = tmp->next;
    if (tmp->content < med)
    {
        data.nb_push++;
        ft_pb();
        if (next != NULL)
            ft_debut_stacka(next, med);
    }
    return (1);
}

int ft_end_stacka(int med)
{
    if (data.last_stacka->content < med)
    {
        data.nb_push++;
        ft_rra();
        ft_pb();
        if (data.last_stacka != NULL)
            ft_end_stacka(med);
    }
    return (1);
}

int ft_mid_stack_a(int med,int i_med)
{
     if (data.nb_push >= i_med)
        return (1);
    if ((*data.stack_a)->content >= med)
    {
        ft_ra();
        ft_mid_stack_a(med, i_med);
    }
    if ((*data.stack_a)->content < med)
    {
        data.nb_push ++;
        ft_pb();
        ft_mid_stack_a(med, i_med);
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
void ft_putdown(int med)
{
    while ((*data.stack_a)->content < med)
        ft_ra();
}
void ft_make_stack_b(int med, int i)
{
    ft_debut_stacka(*(data.stack_a),med);
    ft_end_stacka(med);
    ft_mid_stack_a(med,i);
}
int ft_solve_hundred(void)
{

        data.nb_push = 0;
        ft_find_mediane(data.stack_a, data.len_a);
        ft_make_stack_b(data.med.one, data.med.i_one);
        data.len_b = data.nb_push;
        ft_insert();
        ft_putdown(data.med.one);
        data.last_stackb = NULL;
        data.nb_push = 0;
        while ((*data.stack_a)->content >= data.med.one)
        {
            ft_pb();
            data.nb_push++;
        }
        data.len_b = data.nb_push;
        ft_insert();       
        while ((*data.stack_a)->content >data.med.one)
            ft_ra();
        data.last_stackb = NULL;
return (1);
}

void ft_solve_five_hundred(void)
{
    int i;
    data.nb_push = 0;
    ft_find_mediane(data.stack_a, data.len_a);
    ft_make_stack_b(data.med.two,data.med.i_two);
    data.len_b = ft_lstsize(*data.stack_b);
    i = 0;
    while (i < data.med.i_two - data.med.i_one)
    {
        if (((*data.stack_b)->content) >= data.med.one)
            {
                ft_pa();
                i++;}
        else
            ft_rb();
        
    }
    data.len_b = ft_lstsize(*data.stack_b);
    ft_insert();
    ft_putdown(data.med.one);
    data.last_stackb = NULL;
    while ((*data.stack_a)->content < data.med.two)
        ft_pb();
    ft_insert();
    ft_putdown(data.med.two);
      data.last_stackb = NULL;

    while ((*data.stack_a)->content >= data.med.two)
        ft_pb();
    i = 0;
    while (i < data.med.i_three - data.med.i_two)
    {
        if (((*data.stack_b)->content) >= data.med.three)
            {
                ft_pa();
                i++;}
        else
            ft_rb();
    }
    ft_insert();
    ft_putdown(data.med.three);
    data.last_stackb = NULL;
    while ((*data.stack_a)->content >= data.med.three)
        ft_pb();
    ft_insert();
    while ((*data.stack_a)->content >= data.med.three)
        ft_ra();
}


void ft_solve_five_hundredbis(void)
{
    int i;

    data.nb_push = 0;
    ft_find_mediane(data.stack_a, data.len_a);
    ft_make_stack_b(data.med.four,data.med.i_four);
    data.len_b = ft_lstsize(*data.stack_b);
    i = 0;
    while (i < data.med.i_four - data.med.i_two)
    {
        if (((*data.stack_b)->content) >= data.med.two)
            {
                ft_pa();
                i++;}
        else
            ft_rb();
    }
    i = 0;
    while (i < data.med.i_two - data.med.i_one)
    {
        if (((*data.stack_b)->content) >= data.med.one)
            {
                ft_pa();
                i++;}
        else
            ft_rb();
    }
    data.len_b = ft_lstsize(*data.stack_b);
    ft_insert();
    ft_putdown(data.med.one);
    data.last_stackb = NULL;
    while (((*data.stack_a)->content) < data.med.two)
        ft_pb();
    ft_insert();
    ft_putdown(data.med.two);
    data.last_stackb = NULL;
 //   ft_print_stack(data.stack_a);
  //  ft_print_stack(data.stack_b);
    while (((*data.stack_a)->content) < data.med.four)
        ft_pb();
   //     printf("djd\n");
  //  ft_print_stack(data.stack_a);
//    printf("pkk");
  //  ft_print_stack(data.stack_b);
    //        printf("djd\n");
        i = 0;
  //   printf("MED %d",data.med.three);
    while (i < data.med.i_four - data.med.i_three)
    {
        if (((*data.stack_b)->content) >= data.med.three)
        {
            ft_pa();
            i++;
        }
        else
        { 
            ft_rb();
        }
    }    
    ft_insert();
    ft_putdown(data.med.three);
     data.len_b = ft_lstsize(*data.stack_b);
    data.last_stackb = NULL;
    while (((*data.stack_a)->content) < data.med.four)
        ft_pb();
    ft_insert();
    ft_putdown(data.med.four);
  //  ft_print_stack(data.stack_a);
  //  ft_print_stack(data.stack_b);


    data.last_stackb = NULL;
   while (((*data.stack_a)->content) >= data.med.four)
        ft_pb();
    data.len_b = ft_lstsize(*data.stack_b);
  //      ft_print_stack(data.stack_a);
  //  ft_print_stack(data.stack_b);
    i = 0;
    while (i < data.med.i_six - data.med.i_four)
    {
        if (((*data.stack_b)->content) >= data.med.six)
        {
            ft_pa();
        }
        else
        { 
            i++;
            ft_rb();
        }
    }
    i =0;
    while (i < data.med.i_five - data.med.i_four)
    {
        if (((*data.stack_b)->content) >= data.med.five)
        {
            ft_pa();
        }
        else
        { 
            i++;
            ft_rb();
        }
    }
        ft_insert();
    ft_putdown(data.med.five);
 //   ft_print_stack(data.stack_a);
  //  ft_print_stack(data.stack_b);
    data.last_stackb = NULL;
    while (((*data.stack_a)->content) < data.med.six)
        ft_pb();
    ft_insert();
    ft_putdown(data.med.six);
    //    ft_print_stack(data.stack_a);
  //  ft_print_stack(data.stack_b);
      data.last_stackb = NULL;
    while (((*data.stack_a)->content) >= data.med.six)
        ft_pb();
    i = 0;
    data.len_b = ft_lstsize(*data.stack_b);
    while (i < data.med.i_seven - data.med.i_six)
    {
        if (((*data.stack_b)->content) >= data.med.seven)
        {
            ft_pa();
        }
        else
        { 
            i++;
            ft_rb();
        }
    }
    ft_insert();
    ft_putdown(data.med.seven);
      //  ft_print_stack(data.stack_a);
    //    printf("OK");
  //  ft_print_stack(data.stack_b);
        data.last_stackb = NULL;
    while (((*data.stack_a)->content) >= data.med.seven)
        ft_pb();
    ft_insert();
    while (((*data.stack_a)->content) >= data.med.seven)
        ft_ra();
      //  ft_print_stack(data.stack_a);
    }
