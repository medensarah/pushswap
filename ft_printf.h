/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 05:06:35 by smedenec          #+#    #+#             */
/*   Updated: 2025/07/30 13:06:56 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
void	dispatch(char c, va_list args, int *count);
void	count_print(char c, int *count);
void	ft_putstr(va_list args, int *count);
void	ft_putnbr(int n, int *count);
void	putnbr_unsigned(unsigned int n, int *count);
void	number_decimal(va_list args, int *count);
void	number_unsigned(va_list args, int *count);
void	number_hexa(va_list args, char c, int *count);
void	puthexa(unsigned long n, char c, int *count);
void	number_adress(va_list args, char c, int *count);

#endif
