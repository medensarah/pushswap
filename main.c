/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:53:26 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/21 00:18:30 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	//int	i;
	//i = 1;
	//argv[1] = "123-\t12\b--79819885353+";
	t_list	*stack_a;
	int	*stack_b;
	//int	i;

	//i = 0;
	stack_a = NULL;
	stack_b = NULL;
	stack_a = init_parsing(argc, argv);
	while (stack_a)
	{
		printf("nbr %d\n", stack_a->nbr);
		stack_a = stack_a->next;
	}
//	if (!stack_a)
//		return (error(5), free_fail(&stack_a, NULL), 0);
	stack_b = malloc(sizeof (int) * (argc + 1));
//	if (!stack_b)
//		return (free_fail(&stack_a, NULL), 0);
	//printf(LIGREEN"The stack is sorted in ascending order\n"NONE);
	//free_fail(&stack_a, &stack_b);
	return (1);
}

void	*free_fail(int **stack_a, int **stack_b)
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
