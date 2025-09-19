/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:36:35 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/19 21:42:14 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	if (size != 0 && nmemb > (size_t) - 1 / size)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (ptr == NULL)
		return (NULL);
	while (i < nmemb * size)
		ptr[i++] = 0;
	return ((void *)ptr);
}
// int	main(void)
// {
// 	size_t	nmemb;
// 	size_t	size;

// 	nmemb = 3;
// 	size = 600;
// 	printf("%s\n", (char *)ft_calloc(nmemb, size));
// 	return (0);
// }
