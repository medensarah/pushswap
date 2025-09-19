/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:49:19 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/19 21:39:30 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (n--)
	{
		if (s1[i] && s2[i] && (s1[i] == s2[i]))
			i++;
		else
		{
			if (((unsigned char)s1[i] - (unsigned char)s2[i]) > 0)
				return (1);
			else if (((unsigned char)s1[i] - (unsigned char)s2[i]) < 0)
				return (-1);
		}
	}
	return (0);
}
// int	main(void)
// {
// 	printf("return = %d\n", ft_strncmp("abcdef", "abc\375xx", 6));
// }
