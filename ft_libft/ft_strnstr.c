/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:05:43 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/19 21:39:27 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;
	int		stock;

	i = 0;
	j = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	while (s1[i] && (n > 0))
	{
		j = 0;
		stock = 0;
		while ((s1[i + j] == s2[j]) && (n > 0))
		{
			if (!s2[j + 1])
				return ((char *)&s1[i]);
			j++;
			n--;
			stock++;
		}
		n += stock;
		i++;
		n--;
	}
	return (NULL);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*str;
// 	str = ft_strnstr("aaabcabcd", "abcd", 9);

// 	printf("%s\n", str);
// 	return (0);
// }
