/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:53:26 by smedenec          #+#    #+#             */
/*   Updated: 2025/07/31 22:21:59 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "pushswap.h"

int	main(int argc, char **argv)
{
	//int	i;
	//i = 1;
	//argv[1] = "123-\t12\b--79819885353+";
	int	*stack_a;
	int	*stack_b;
	//int	i;

	//i = 0;
	stack_a = NULL;
	stack_b = NULL;
	stack_a = init_parsing(argc, argv);
	if (!stack_a)
		return (error(5), free_fail(&stack_a, NULL), 0);

	stack_b = malloc(sizeof (int) * (argc + 1));
	if (!stack_b)
		return (free_fail(&stack_a, NULL), 0);
	printf(LIGREEN"Parsing and build passed\n"NONE);
	//while (stack_a[i])
	printf("la chaine = %d\n"NONE, stack_a[0]);

	printf(LIGREEN"The stack is sorted in ascending order\n"NONE);
	free_fail(&stack_a, &stack_b);
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
