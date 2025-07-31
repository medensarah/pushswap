/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:53:26 by smedenec          #+#    #+#             */
/*   Updated: 2025/07/31 16:35:25 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "pushswap.h"

int atoi_range(const char *str, int *nbr)
{
	int		i = 0;
	int		sign = 1;
	long	result = 0;

	while (str[i])
	{
		if (str[i] == '-')
			sign *= -1;
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - '0');
		i++;
	}
	if ((sign == 1 && result > INT_MAX ) ||
	(sign == -1 && -result < INT_MIN))
				return (1);
	*nbr = (int)(sign * result);
	return (0);
}
int	check_number(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' ||
	(str[i] >= '\t' && str[i] <= '\r') || str[i] == '-' ||
	str[i] == '+'))
		return (1);
	i = 0;
	return (0);
}
