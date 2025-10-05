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
	t_list	*tmp;
	// boucle de stack_a
	ft_printf("stack_a :\n");
	tmp = *stack_a;
	while (tmp)
	{
		ft_printf("nbr %d, val %d\n", tmp->nbr, tmp->value);
		tmp = tmp->next;
	}
	ft_printf("____\n");
	ft_printf("5");
	return (1);
}