/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:52:29 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/19 21:41:40 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*src_char;
	char		*dest_char;

	src_char = src;
	dest_char = dest;
	if (!src_char && !dest_char)
		return (NULL);
	if (src >= dest)
	{
		while (n--)
			*dest_char++ = *src_char++;
	}
	else
	{
		src_char += n - 1;
		dest_char += n - 1;
		while (n--)
		{
			if (n)
				*dest_char-- = *src_char--;
			else
				*dest_char = *src_char;
		}
	}
	return (dest);
}
// int	main(void)
// {
// 	size_t		n;
// 	char	dest[] = "Alumnis";
// 	char	src[] = "Piscineux";
// 	char	*cpy;

// 	n = 4;
// 	cpy = ft_memmove(dest, src, n);
// 	printf("%s\n", cpy);

// 	char	test_dest[] = "Alumnis";
// 	char	test_src[] = "Piscineux";
// 	char	*test_cpy;

// 	test_cpy = memmove(test_dest, test_src, n);
// 	printf("memmove = %s\n", test_cpy);
// 	return (0);
// }
