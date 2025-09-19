/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:36:35 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/19 21:39:25 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	ptr = (char *)s;
	i = ft_strlen(ptr);
	ptr = ptr + i -1;
	if ((char)c == '\0')
		return (++ptr);
	while (i--)
	{
		if (*ptr-- == (char)c)
			return (++ptr);
	}
	if (*ptr == (char)c)
		return (ptr);
	return (NULL);
}
// int	main(void)
// {
// 	char	str[] = "francinetee";
// 	int	c;

// 	c = 'f';
// 	printf("%s\n", ft_strrchr(NULL, c));
// 	return (0);
// }
