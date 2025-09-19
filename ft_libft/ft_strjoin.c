/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:36:35 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/19 21:39:56 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

static int	ft_len(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;

	if (s1)
		len_s1 = ft_strlen(s1);
	else
		len_s1 = 0;
	if (s2)
		len_s2 = ft_strlen(s2);
	else
		len_s2 = 0;
	return (len_s1 + len_s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len;
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_len(s1, s2);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (s1[j])
	{
		str[j] = s1[j];
		j++;
	}
	while (s2[k])
	{
		str[j + k] = s2[k];
		k++;
	}
	str[j + k] = '\0';
	return (str);
}
// int	main(void)
// {
// 	char	s1[] = "aaa";
// 	char	s2[] = "eee";
// 	char	*str;

// 	str = ft_strjoin(s1, s2);
// 	printf("%s\n", str);
// 	free(str);
// 	return (0);
// }
