/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:36:35 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/19 21:39:45 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s;

	s = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (s);
	while (src[i] && (--size))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s);
}
// int	main(void)
// {
// 	size_t	size;
// 	char	dst[] = "42up";
// 	char	src[] = "";

// 	size = 2;
// 	printf("mine = %zu\n", ft_strlcpy(dst, src, size));
// 	printf("dest = %s\n", dst);
// 	printf("src = %s\n", src);

// 	size_t	siz;
// 	char	dest[] = "42up";
// 	char	srce[] = "";

// 	siz = 2;
// 	printf("real = %zu\n", strlcpy(dest, srce, siz));
// 	printf("dest = %s\n", dest);
// 	printf("src = %s\n", srce);
// 	return (0);
// }
