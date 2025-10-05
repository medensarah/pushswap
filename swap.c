/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 02:15:06 by smedenec          #+#    #+#             */
/*   Updated: 2025/10/05 22:58:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_a(t_list **stack_a)
{
	t_list	*tmp_1;
	t_list	*tmp_2;

	if (!stack_a || !*stack_a || (*stack_a)->next == NULL)
		return ;
	tmp_1 = *stack_a;
	tmp_2 = tmp_1->next;
	tmp_1->next = tmp_2->next;
	tmp_2->next = tmp_1;
	*stack_a = tmp_2;
	ft_printf("sa\n");
}

void	rotate_a(t_list **stack_a)
{
	t_list	*first;
	t_list	*last;

	if (!stack_a || !*stack_a)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	ft_printf("ra\n");
}
//Le premier élément devient le dernier.

void    reverse_rotate_a(t_list **stack_a)
{
    t_list  *prev;
    t_list  *last;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return ;
    prev = NULL;
    last = *stack_a;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *stack_a;
    *stack_a = last;
	ft_printf("rra\n");
}
//Le dernier élément devient le premier.

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	ft_printf("pb\n");
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_b || !*stack_b || !stack_a)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	ft_printf("pa\n");
}
