/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:53:26 by smedenec          #+#    #+#             */
/*   Updated: 2025/10/09 01:49:42 by marvin           ###   ########.fr       */
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
	sort_init(&stack_a, &stack_b);
	// boucle de stack_a
	ft_printf("stack_a :\n");
	t_list	*tmp = stack_a;
	while (tmp)
	{
		ft_printf("nbr %d\n", tmp->nbr);
		tmp = tmp->next;
	}
	ft_printf("____\n");
	// boucle de stack_b
	ft_printf("stack_b :\n");
	tmp = stack_b;
	while (tmp)
	{
		ft_printf("nbr %d\n", tmp->nbr);
		tmp = tmp->next;
	}
	ft_printf("____\n");
	// // ici le test
	// ft_printf("ra\n");
	// rotate_a(&stack_a);
	// ft_printf("____\n");
	// // boucle de stack_a
	// ft_printf("stack_a :\n");
	// tmp = stack_a;
	// while (tmp)
	// {
	// 	ft_printf("nbr %d\n", tmp->nbr);
	// 	tmp = tmp->next;
	// }
	// ft_printf("____\n");
	// // boucle de stack_b
	// ft_printf("stack_b :\n");
	// tmp = stack_b;
	// while (tmp)
	// {
	// 	ft_printf("nbr %d\n", tmp->nbr);
	// 	tmp = tmp->next;
	// }
	// ft_printf("____\n");
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
// 	// ici le test
// 	ft_printf("ra\n");
// 	rotate_a(&stack_a);
// 	ft_printf("____\n");
// 	// boucle de stack_a
// 	ft_printf("stack_a :\n");
// 	tmp = stack_a;
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
