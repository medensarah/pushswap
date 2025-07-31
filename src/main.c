/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:53:26 by smedenec          #+#    #+#             */
/*   Updated: 2025/07/31 17:45:35 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "pushswap.h"

int	main(int argc, char **argv)
{
	//int	i;
	//i = 1;
	//argv[1] = "123-\t12\b--79819885353+";
	if (init(argc, argv))
	{
		printf(LIRED"Parsing and build failed\n"NONE);
		//printf(LIRED"The stack isnt sorted in ascending order\n"NONE);
		return (1);
	}
	printf(LIGREEN"Parsing and build passed\n"NONE);
	//printf(LIGREEN"The stack is sorted in ascending order\n"NONE);
	return (0);
}
