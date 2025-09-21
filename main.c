/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:53:26 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/21 02:23:47 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = init_parsing(argc, argv);
	if (!stack_a)
		return (0);
	//Pour voir en temps reel
	while (stack_a)
	{
		printf("nbr %d\n", stack_a->nbr);
		stack_a = stack_a->next;
	}
	// //if stack is sorted
	// printf(LIGREEN"The stack is sorted in ascending order\n"NONE);
	//free everything
	free_fail(&stack_a, &stack_b);
	return (1);
}

void	*free_fail(t_list **stack_a, t_list **stack_b)
{
	if (stack_a && *stack_a)
	{
		free(*stack_a);
		*stack_a = NULL;
	}
	if (stack_b && *stack_b)
	{
		free(*stack_b);
		*stack_b = NULL;
	}
	return (NULL);
}
