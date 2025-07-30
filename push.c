/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:53:26 by smedenec          #+#    #+#             */
/*   Updated: 2025/07/30 18:38:56 by smedenec         ###   ########.fr       */
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
		return (error(1), 1);
	if (argc < 6 || argc > 101)
		return (error(2), 1);
	if (check_numeric(argv))
		return (error(3), 1);
	else
		return (0);
}

int	check_numeric(char **argv)
{
	int	i;
	int	y;

	printf("Checking %s...\n", argv[0]);
	i = 1;
	y = 0;
	while (argv[i])
	{
		y = 0;
		while (argv[i][y])
		{
			while (argv[i][y] == ' ' ||
				(argv[i][y] >= '\t' && argv[i][y] <= '\r'))
				y++;
			if (argv[i][y] == '\0')
				break ;
			if (argv[i][y] >= '0' && argv[i][y] <= '9')
				y++;
			else
				return (1);
		}
		i++;
	}
	printf(GREEN"Check_numeric passed\n"NONE);
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
	else
		printf("Error: ?\n");
}

int	main(int argc, char **argv)
{
	if (!parsing(argc, argv))
	{
		printf(LIGREEN"Parsing passed\n"NONE);
		printf(LIGREEN"The stack is sorted in ascending order\n"NONE);
		return (0);
	}
	printf(RED"Parsing failed\n"NONE);
	printf(LIRED"The stack isnt sorted in ascending order\n"NONE);
	return (1);
}
