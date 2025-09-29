/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:53:26 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/29 17:28:39 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*init_parsing(int argc, char **argv)
{
	t_list	*stack_a;

	if (!argv || argc <= 1)
		return (NULL);
	if (argc <= 2 || argc > 500)
		return (error());
	if (!check_list(argv))
		return (error());
	stack_a = build_list(argc, argv);
	if (!stack_a)
		return (NULL);
	return (stack_a);
}

t_list	*build_list(int argc, char **argv)
{
	int		i;
	int		nbr;
	t_list	*stack_a;
	t_list	*node;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		if (!atoi_range(argv[i], &nbr))
			return (free_fail(&stack_a, NULL), NULL);
		node = create_node(nbr);
		if (!node)
			return (free_fail(&stack_a, NULL), NULL);
		if (i == 1)
			stack_a = node;
		else
			lst_addback(&stack_a, node);
		i++;
	}
	return (stack_a);
}

int	check_list(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!check_number(argv[i]))
			return (0);
		if (!atoi_range(argv[i], NULL))
			return (0);
		if (!check_double(argv))
			return (0);
		i++;
	}
	return (1);
}

void	*error()
{
	printf("Error\n");
	return (NULL);
}
