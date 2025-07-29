/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 04:48:37 by smedenec          #+#    #+#             */
/*   Updated: 2025/07/29 14:54:50 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		*count;
	int		num;
	va_list	args;

	if (!s)
		return (-1);
	va_start(args, s);
	num = 0;
	count = &num;
	while (*s)
	{
		if (*s == '%')
			dispatch(*++s, args, count);
		else
		{
			write(1, s, 1);
			(*count)++;
		}
	s++;
	}
	return (num);
}
