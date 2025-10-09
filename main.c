/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:53:26 by smedenec          #+#    #+#             */
/*   Updated: 2025/10/10 01:07:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		argv_malloced;

	argv_malloced = 0;
	stack_a = NULL;
	stack_b = NULL;
	stack_a = init_parsing(argc, &argv, &argv_malloced);
	if (stack_a)
		sort_init(&stack_a, &stack_b);
	free_fail(&stack_a, &stack_b);
	if (argv_malloced)
		free_split(argv);
	return (1);
}
//./pushswap $(cat numbers.txt) | ~/checker $(cat numbers.txt)

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

void	*free_split(char **argv)
{
	int	i;

	i = 0;
	if (!argv)
		return (NULL);
	while (argv[i])
	{
		free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	free(argv);
	argv = NULL;
	return (NULL);
}
// // boucle de stack_a
// 	ft_printf("stack_a :\n");
// 	t_list	*tmp = stack_a;
// 	while (tmp)
// 	{
// 		ft_printf("nbr %d\n", tmp->nbr);
// 		tmp = tmp->next;
// 	}
// 	ft_printf("____\n");
// 	// boucle de stack_b
// 	ft_printf("stack_b :\n");
// 	tmp = stack_b;
// 	while (tmp)
// 	{
// 		ft_printf("nbr %d\n", tmp->nbr);
// 		tmp = tmp->next;
// 	}
// 	ft_printf("____\n");
