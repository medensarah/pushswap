/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:53:26 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/29 16:43:32 by smedenec         ###   ########.fr       */
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
	// boucle de stack_a
	printf("stack_a :\n");
	t_list *tmp = stack_a;
	while (tmp)
	{
		printf("nbr %d\n", tmp->nbr);
		tmp = tmp->next;
	}
	printf("____\n");
	// boucle de stack_b
	printf("stack_b :\n");
	tmp = stack_b;
	while (tmp)
	{
		printf("nbr %d\n", tmp->nbr);
		tmp = tmp->next;
	}
	printf("____\n");
	// ici le test
	printf("ra\n");
	rotate_a(&stack_a);
	printf("____\n");
	// boucle de stack_a
	printf("stack_a :\n");
	tmp = stack_a;
	while (tmp)
	{
		printf("nbr %d\n", tmp->nbr);
		tmp = tmp->next;
	}
	printf("____\n");
	// boucle de stack_b
	printf("stack_b :\n");
	tmp = stack_b;
	while (tmp)
	{
		printf("nbr %d\n", tmp->nbr);
		tmp = tmp->next;
	}
	printf("____\n");
	// //if stack is sorted
	// printf(LIGREEN"The stack is sorted in ascending order\n"NONE);
	free_fail(&stack_a, &stack_b);
	return (1);
}

void	*free_fail(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (stack_a && *stack_a)
	{
		while (*stack_a)
		{
			tmp = (*stack_a)->next;
			free(*stack_a);
			*stack_a = tmp;
		}
	}
	if (stack_b && *stack_b)
	{
		while (*stack_b)
		{
			tmp = (*stack_b)->next;
			free(*stack_b);
			*stack_b = tmp;
		}
	}
	return (NULL);
}
