/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:00:01 by marvin            #+#    #+#             */
/*   Updated: 2025/10/05 20:00:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sort_id(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		len_a;
	int		*tab;
	t_list	*tmp;

	len_a = list_len(stack_a);
	tab = malloc(sizeof(int) * len_a);
	if (!tab)
		return (free_fail(stack_a, NULL), 0);
	tmp = *stack_a;
	i = 0;
	while (tmp)
	{
    	tab[i++] = tmp->nbr;
    	tmp = tmp->next;
	}
	if (len_a <= 5)
		only_five(stack_a, stack_b);
	else if (len_a <= 100)
		radix_100(stack_a, stack_b);
	else
		radix_500(stack_a, stack_b);
	return (1);
}

int	list_len(t_list **stack_a)
{
	int		i;
	t_list	*tmp;

	tmp = *stack_a;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}