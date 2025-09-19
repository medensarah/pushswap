/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:36:35 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/19 21:39:18 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	len_str;
	int		j;

	j = 0;
	if (!s)
		return (NULL);
	len_str = ft_strlen(s);
	if (start >= len_str)
		len = 0;
	if (len > len_str - start)
		len = len_str - start;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (len-- && s[j + start])
	{
		str[j] = s[j + start];
		j++;
	}
	str[j] = '\0';
	return (str);
}
// int	main(void)
// {
// 	char			s[] = "Push_swap&Pipex";
// 	unsigned int	start;
// 	size_t			len;
// 	char			*str;

// 	start = 3;
// 	len = 3;
// 	str = ft_substr(s, start, len);
// 	printf("%s\n", str);
// 	free(str);
// 	return (0);
// }
