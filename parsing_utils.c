/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:53:26 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/29 12:03:43 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static long long	parse_number(const char *str, int *i, int *sign)
{
	long long	result;

	*i = 0;
	*sign = 1;
	result = 0;
	while (str[*i] == ' ' || str[*i] == '\b' || str[*i] == '\t'
		|| str[*i] == '\n' || str[*i] == '\v' || str[*i] == '\f'
		|| str[*i] == '\r')
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[(*i)++] == '-')
			*sign = -1;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

int	atoi_range(const char *str, int *nbr)
{
	int			i;
	int			sign;
	long long	result;

	result = parse_number(str, &i, &sign);
	if (str[i] != '\0')
		return (0);
	if ((sign == 1 && result > INT_MAX) || (sign == -1 && (-result < INT_MIN)))
		return (0);
	if (nbr)
		*nbr = (int)(sign * result);
	return (1);
}

int	check_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\b' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '\0')
		return (0);
	if (str[i] && str[i + 1] && str[i] == '-' && str[i + 1] == '0')
	{
		str[i] = '0';
		str[i + 1] = '\0';
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '0' && str[i + 1] && str[i + 1] == '0')
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_double(char **argv)
{
	int	i;
	int	y;

	i = 1;
	y = 1;
	while (argv[i])
	{
		y = i;
		while (argv[y])
		{
			if (i != y)
			{
				if (!(diff_nbr(argv[i], argv[y])))
					return (0);
			}
			y++;
		}
		i++;
	}
	return (1);
}

int	diff_nbr(const char *s1, const char *s2)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s1[i] && !(s1[i] >= '0' && s1[i] <= '9'))
		i++;
	while (s2[y] && !(s2[y] >= '0' && s2[y] <= '9'))
		y++;
	while (s1[i] || s2[y])
	{
		if ((s1[i] != s2[y]) || (s1[0] == '-' && s2[0] != '-')
			|| (s2[0] == '-' && s1[0] != '-'))
			return (1);
		i++;
		y++;
	}
	return (0);
}
