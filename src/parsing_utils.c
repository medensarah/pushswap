/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:53:26 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/04 02:55:45 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "pushswap.h"

int	atoi_range(const char *str, int *nbr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i])
	{
		if (str[i] == '-')
			sign *= -1;
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - '0');
		i++;
	}
	if ((sign == 1 && result > INT_MAX) || (sign == -1 && - result < INT_MIN))
		return (0);
	*nbr = (int)(sign * result);
	return (1);
}

int	check_number(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(allowed_space(str[i])) && !(str[i] >= '0' && str[i] <= '9')
			&& !(str[i] == '-') && !(str[i] == '+'))
			return (0);
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

int	allowed_space(char c)
{
	if ((c == ' ' || c == '\b' || c == '\t' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r'))
		return (1);
	return (0);
}
