/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:53:26 by smedenec          #+#    #+#             */
/*   Updated: 2025/07/31 19:08:37 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "pushswap.h"

int	init_parsing(int argc, char **argv, int *stack_a)
{
	if (!argv || argc <= 1)
		return (error(1), 0);
	if (argc < 6 || argc > 101)
		return (error(2), 0);
	if (check_list(argv))
		return (error(3), 0);
	*stack_a = *build_list(argc, argv, stack_a);
	if (!stack_a)
		return (error(4), 0);
	return (1);
}

int	*build_list(int argc, char **argv, int *stack_a)
{
	int		i;
	//int		*stack_a;
	int		nbr;

	i = 1;
	argc--;
	stack_a = malloc(sizeof (int) * (argc + 1));
	if (!stack_a)
		return (0);
	while (argv[i])
	{
		if (atoi_range(argv[i], &nbr))
		{
			free(stack_a);
			stack_a = NULL;
			return (0);
		}
		stack_a[i] = nbr;
		printf("Stack_A[%d] = %d\n", i, stack_a[i]);
		i++;
	}
	stack_a[i] = '\0';
	printf(GREEN"build_list passed\n"NONE);
	return (stack_a);
}

int	check_list(char **argv)
{
	int	i;

	printf("Checking %s...\n", argv[0]);
	i = 1;
	while (argv[i])
	{
		if (check_number(argv[i]))
			return (error(3), 0);
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
		printf(RED"Error : Accepted numbers must be between 5 and 100\n"NONE);
	else if (err == 3)
		printf(RED"Error : Only numbers are allowed in argument\n"NONE);
	else if (err == 4)
		printf(RED"Error : Allowed number range is between '%d' and '%d'\n"
			NONE, INT_MIN, INT_MAX);
	else if (err == 5)
		printf(RED"Error : '\n");
	else
		printf(RED"Error: ?\n"NONE);
}
