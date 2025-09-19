/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 02:05:26 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/19 21:39:33 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	i;

	i = 0;
	if (!f || !s)
		return (NULL);
	dest = malloc(sizeof(char) *(ft_strlen(s) + 1));
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
// int	main(void)
// {
// 	char	str[] = "Hackathon";

// 	char *cpy = ft_strmapi(str, ft_assign);
// 	printf("le int = %s\n", cpy);
// 	return(0);
// }
