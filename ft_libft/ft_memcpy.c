/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:05:43 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/19 21:41:43 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*src_char;
	char		*dest_char;

	dest_char = dest;
	src_char = src;
	if ((!(dest_char) && !(src_char)))
		return (NULL);
	while (n--)
		*dest_char++ = *src_char++;
	return (dest);
}
// int	main(void)
// {
// 	size_t		n;
// 	char	dest[] = "TERMINAL";
// 	char	src[] = "SHELL";
// 	char	*cpy;

// 	n = 15;
// 	cpy = ft_memcpy(dest, src, n);
// 	printf("%s\n", cpy);

// 	char	test_dest[] = "TERMINAL";
// 	char	test_src[] = "SHELL";
// 	char	*test_cpy;

// 	test_cpy = memcpy(test_dest, test_src, n);
// 	printf("test_memcpy = %s\n", test_cpy);
// 	return (0);
// }
