/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:53:26 by smedenec          #+#    #+#             */
/*   Updated: 2025/10/11 20:34:56 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*init_parsing(int argc, char ***argv, int *argv_malloced)
{
	t_list	*stack_a;
	int		i;

	i = 1;
	if (!(*argv) || argc <= 1)
		return (NULL);
	if (argc > 700)
		return (error());
	if (argc == 2 && (*argv)[1])
	{
		*argv = ft_split((*argv)[1], ' ');
		if (!(*argv))
			return (NULL);
		*argv_malloced = 1;
		argc = strlentable(*argv);
		i = 0;
	}
	if ((*argv)[1] && !check_list(*argv, i))
		return (error());
	stack_a = build_list(argc, *argv, i);
	if (!stack_a)
		return (NULL);
	return (stack_a);
}

int	strlentable(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
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
		if (!atoi_range(argv[i], &nbr, 0))
			return (NULL);
		node = create_node(nbr);
		if (!node)
			return (NULL);
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

int	check_list(char **argv, int i)
{
	while (argv[i])
	{
		if (!check_number(argv[i]))
			return (0);
		if (!atoi_range(argv[i], NULL, 1))
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
