/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:53:26 by smedenec          #+#    #+#             */
/*   Updated: 2025/07/31 17:44:54 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "pushswap.h"

int	init(int argc, char **argv)
{
	if (!argv || argc <= 1)
		return (error(1), 1);
	if (argc < 6 || argc > 101)
		return (error(2), 1);
	if (check_list(argv))
		return (error(3), 1);
	if (build_list(argc, argv))
		return (error(4), 1);
	else
		return (0);
}

int	build_list(int argc, char **argv)
{
	int		i;
	int		*stack_a;
	int		nbr;

	i = 1;
	argc--;
	stack_a = malloc(sizeof (int) * (argc + 1));
	if (!stack_a)
		return (1);
	while (argv[i])
	{
		if (atoi_range(argv[i], &nbr))
		{
			free(stack_a);
			stack_a = NULL;
			return (1);
		}
		stack_a[i] = nbr;
		printf("Stack_A[%d] = %d\n", i - 1, stack_a[i]);
		i++;
	}
	stack_a[i] = '\0';
	printf(GREEN"build_list passed\n"NONE);
	return (0);
}

int	check_list(char **argv)
{
	int	i;

	printf("Checking %s...\n", argv[0]);
	i = 1;
	while (argv[i])
	{
		if (check_number(argv[i]))
			return (1);
		i++;
	}
	printf(GREEN"check_list passed\n"NONE);
	return (0);
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
