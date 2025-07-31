/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:21:29 by smedenec          #+#    #+#             */
/*   Updated: 2025/07/31 16:32:41 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	number_adress(va_list args, char c, int *count)
{
	unsigned long	l;

	l = va_arg(args, unsigned long);
	if (l == 0)
	{
		write(1, "(nil)", 5);
		(*count) += 5;
	}
	else
	{
		write(1, "0x", 2);
		(*count) += 2;
		puthexa(l, c, count);
	}
}

void	number_hexa(va_list args, char c, int *count)
{
	unsigned int	l;

	l = va_arg(args, unsigned int);
	if (l == 0)
		count_print('0', count);
	else
		puthexa(l, c, count);
}

void	number_decimal(va_list args, int *count)
{
	int	n;

	n = va_arg(args, int);
	ft_putnbr(n, count);
}

void	number_unsigned(va_list args, int *count)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	putnbr_unsigned(n, count);
}

void	putnbr_unsigned(unsigned int n, int *count)
{
	if (n < 10)
	{
		write(1, &(char){n + '0'}, 1);
		(*count)++;
	}
	if (n >= 10)
	{
		putnbr_unsigned(n / 10, count);
		putnbr_unsigned(n % 10, count);
	}
}
