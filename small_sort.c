/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:36:37 by marvin            #+#    #+#             */
/*   Updated: 2025/10/05 21:36:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int only_five(t_list **stack_a, t_list **stack_b, int len_a)
{
	if (len_a == 2)
        swap_a(stack_a);
    else if (len_a == 3)
        sort_three(stack_a);
    else if (len_a == 4)
        sort_four(stack_a, stack_b);
    else
		sort_five(stack_a, stack_b);
	return (1);
}

void	sort_three(t_list **stack_a)
{
	int a;
    int b;
    int c;

    a = (*stack_a)->value;
    b = (*stack_a)->next->value;
    c = (*stack_a)->next->next->value;
    if (a > b && b < c && a < c)
        swap_a(stack_a);
    else if (a > b && b > c)
    {
        swap_a(stack_a);
        reverse_rotate_a(stack_a);
    }
    else if (a > b && b < c && a > c)
        rotate_a(stack_a);
    else if (a < b && b > c && a < c)
    {
        swap_a(stack_a);
        rotate_a(stack_a);
    }
    else if (a < b && b > c && a > c)
        reverse_rotate_a(stack_a);
}

void sort_four(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
    push_min_to_b(stack_a, stack_b, tmp);
    sort_three(stack_a);
    push_a(stack_a, stack_b);
	ft_printf("''4''\n");
}
void sort_five(t_list **stack_a, t_list **stack_b)
{
    t_list  *tmp;

	tmp = *stack_a;
    push_min_to_b(stack_a, stack_b, tmp);
    push_min_to_b(stack_a, stack_b, tmp);
    sort_three(stack_a);
    push_a(stack_a, stack_b);
    push_a(stack_a, stack_b);
}

void push_min_to_b(t_list **stack_a, t_list **stack_b, t_list *tmp)
{
    int     min_index;
    int     min_value;
    int     i;

    i = 0;
    min_index = 0;
    min_value = tmp->value;
    while (tmp)
    {
        if (tmp->value < min_value)
        {
            min_value = tmp->value;
            min_index = i;
        }
        tmp = tmp->next;
        i++;
    }
    if (min_index <= i / 2)
        while (min_index-- > 0)
            rotate_a(stack_a);
    else
        while (min_index++ < i)
            reverse_rotate_a(stack_a);
    push_b(stack_a, stack_b);
}
