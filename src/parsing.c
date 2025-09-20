/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:53:26 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/20 02:27:25 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_libft/ft_libft.h"
#include "../ft_printf/ft_printf.h"
#include "pushswap.h"

t_list	*init_parsing(int argc, char **argv)
{
	t_list	*head;

	if (!argv || argc <= 1)
		return (error(1), NULL);
	if (argc <= 1 || argc > 20)
		return (error(2), NULL);
	if (!check_list(argv))
		return (NULL);
	head = build_list(argc, argv);
	if (!head)
		return (error(4), NULL);
	return (head);
}

t_list	*build_list(int argc, char **argv)
{
	int		i;
	int		nbr;
	t_list	*head;
	t_list	*node;

	head = NULL;
	i = 1;
	while (i < argc)
	{
		if (!atoi_range(argv[i], &nbr))
			return (NULL);
		node = create_node(nbr);
		if (!node)
			return (NULL);
		if (i == 1)
			head = node;
		else
			lst_addback(&head, node);
		i++;
	}
	return (head);
}

int	check_list(char **argv)
{
	int	i;

	printf("Checking %s...\n", argv[0]);
	i = 1;
	while (argv[i])
	{
		if (!check_number(argv[i]))
		{
			error(3);
			return (0);
		}
		if (!atoi_range(argv[i], NULL))
		{
			error(4);
			return (0);
		}
		if (!check_double(argv))
		{
			error(5);
			return (0);
		}
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
		printf(RED"Error : Accepted list of numbers must be between 1 and 100\n"
			NONE);
	else if (err == 3)
		printf(RED"Error : Only numbers are allowed in argument\n"NONE);
	else if (err == 4)
		printf(RED"Error : Allowed number range is between '%d' and '%d'\n"
			NONE, INT_MIN, INT_MAX);
	else if (err == 5)
		printf(RED"Error : Numbers in double are not accepted\n"NONE);
	else if (err == 6)
		printf(LIRED"Error : Parsing and build failed\n"NONE);
	else
		printf(RED"Error: ?\n"NONE);
}
