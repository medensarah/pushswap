/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 02:15:06 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/29 13:52:50 by smedenec         ###   ########.fr       */
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
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
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
}
