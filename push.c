/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:53:26 by smedenec          #+#    #+#             */
/*   Updated: 2025/07/30 15:42:56 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//A penser :"The stack is already sorted."
// remoove the -g3 in CFLAGS
// remoove stdio.h et remplacer tous les printf
// add at the end "The stack is sorted in ascending order\n"
#include "ft_printf.h"
#include "pushswap.h"

int	parsing(int argc, char **argv)
{
	if (!argv || argc <= 1)
		return (answer(1), 1);
	if (argc < 6 || argc > 101)
		return (answer(2), 1);
	if (check_stack(argc, argv))
		return (answer(3), 1);
	else
		return (answer(0), 0);
}
int	check_stack(int argc, char **argv)
{
	int i;
	int y;

	printf("Checking %s...\n", argv[0]);
	i = 1;
	y = 0;
	while (argv[i])
	{
		if (!argv[i])
			return (answer(666), 1);
		while (!argv[i][y])
		{
			y++;
		}

		i++;
	}
	return (0);
}

void	answer(int err)
{
	switch (err)
	{
		case 0:
			printf("Parsing passed\n");
			break;
		case 1:
			printf("Error : No numbers entered\n");
			break;
		case 2:
			printf("Error : Accepted numbers must be between 5 and 100\n");
			break;
		case 3:
			printf("Error : Only numbers are allowed in argument\n");
			break;
		case 4:
			printf("Error : Allowed number range is between '%d' and '%d'\n", INT_MIN, INT_MAX);
			break;
		default:
			printf("Error: ?\n");
			break;
	}
}

int	main(int argc, char **argv)
{
	if (!parsing(argc, argv))
	{
		printf("The stack is sorted in ascending order\n");
		return (0);
	}
	printf("Parsing failed\n");
	return (1);
}
