/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:56:53 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/19 21:40:33 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_libft.h"
#include <unistd.h>

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n = n * -1;
			ft_putchar('-', fd);
		}
		if (n < 10)
		{
			ft_putchar(n + '0', fd);
		}
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
	}
}
// int	main()
// {
// 	ft_putnbr_fd(189);
// 	return (0);
// }
