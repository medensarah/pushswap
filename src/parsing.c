/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:53:26 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/04 03:00:48 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "pushswap.h"

int	*init_parsing(int argc, char **argv)
{
	int	*list;

	
	list = NULL;
	if (!argv || argc <= 1)
		return (error(1), NULL);
	if (argc < 6 || argc > 101)
		return (error(2), NULL);
	if (!check_list(argv))
		return (error(3), NULL);
	list = build_list(argc, argv, list);
	if (!list)
		return (error(4), NULL);
	return ((int *)list);
}

int	*build_list(int argc, char **argv, int *stack_a)
{
	int		i;
	//int		*stack_a;
	int		nbr;

	i = 0;
	argc--;
	stack_a = malloc(sizeof (int) * (argc + 1));
	if (!stack_a)
		return (NULL);
	while (argv[i + 1])
	{
		if (!atoi_range(argv[i + 1], &nbr))
		{
			free(stack_a);
			stack_a = NULL;
			return (NULL);
		}
		stack_a[i] = nbr;
		printf("Stack_a[%d] = %d\n", i, stack_a[i]);
		i++;
	}
	stack_a[i] = '\0';
	printf(GREEN"build_list passed\n"NONE);
	return ((int *)stack_a);
}

int	check_list(char **argv)
{
	int	i;

	printf("Checking %s...\n", argv[0]);
	i = 1;
	while (argv[i])
	{
		if (!check_number(argv[i]))
			return (0);
		i++;
	}
	printf(GREEN"check_list passed\n"NONE);
	return (1);
}

void	error(int err)
{
	if (err == 1)
		printf(RED"Error : No numbers entered\n"NONE);
	else if (err == 2)
		printf(RED"Error : Accepted list of numbers must be between 5 and 100\n"NONE);
	else if (err == 3)
		printf(RED"Error : Only numbers are allowed in argument\n"NONE);
	else if (err == 4)
		printf(RED"Error : Allowed number range is between '%d' and '%d'\n"
			NONE, INT_MIN, INT_MAX);
	else if (err == 5)
		printf(LIRED"Error : Parsing and build failed\n"NONE);
	else
		printf(RED"Error: ?\n"NONE);
}
