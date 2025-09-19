/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:36:35 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/19 21:41:46 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*s1_ch;
	char	*s2_ch;
	int		i;

	i = 0;
	s1_ch = (char *)s1;
	s2_ch = (char *)s2;
	while (n--)
	{
		if (s1_ch[i] == s2_ch[i])
			i++;
		else
			return ((unsigned char)s1_ch[i] - (unsigned char)s2_ch[i]);
	}
	return (0);
}
// int	main(void)
// {
// 	char	s1[] = "D'accord";
// 	char	s2[] = "D'abord";

// 	printf("%d\n", ft_memcmp(s1, s2, 7));
// 	return (0);
// }
