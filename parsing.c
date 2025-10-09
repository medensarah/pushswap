/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:53:26 by smedenec          #+#    #+#             */
/*   Updated: 2025/10/09 18:17:11 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*init_parsing(int argc, char **argv)
{
	t_list	*stack_a;
	int		i;

	i = 1;
	if (!argv || argc <= 1)
		return (NULL);
	if (argc > 700)
		return (error());
	if (argc == 2 && argv[1])
	{
		argv = ft_split(argv[1], ' ');
		i = 0;
		while (argv[i])
			i++;
		argc = i;
		i = 0;
	}
	if (!check_list(argv))
		return (error());
	stack_a = build_list(argc, argv, i);
	if (!stack_a)
		return (NULL);
	return (stack_a);
}

t_list	*build_list(int argc, char **argv, int i)
{
	int		nbr;
	t_list	*stack_a;
	t_list	*node;
	int		first;

	stack_a = NULL;
	first = 0;
	while (i < argc)
	{
		if (!atoi_range(argv[i], &nbr))
			return (free_fail(&stack_a, NULL), NULL);
		node = create_node(nbr);
		if (!node)
			return (free_fail(&stack_a, NULL), NULL);
		if (!first)
		{
			stack_a = node;
			first = 1;
		}
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

void	*error(void)
{
	ft_printf("Error\n");
	return (NULL);
}
