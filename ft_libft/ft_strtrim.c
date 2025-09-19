/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:36:35 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/19 21:39:22 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

static int	in_set(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	trim_start(char *s1, char *set)
{
	int	o;

	o = 0;
	while (in_set(s1[o], set) && s1[o])
		o++;
	return (o);
}

static int	trim_end(char *s1, char *set, int len)
{
	int	u;

	len--;
	u = len;
	while (in_set(s1[u], set) && len)
		u--;
	return (u);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		e;
	int		start;
	int		end;
	int		len;
	char	*trim;

	e = 0;
	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	start = trim_start(s1, set);
	end = trim_end(s1, set, len);
	len = end - start + 1;
	if (start > end)
		len = 0;
	trim = malloc(sizeof(char) * (len + 1));
	if (trim == NULL)
		return (NULL);
	while (len--)
	{
		trim[e] = s1[start + e];
		e++;
	}
	trim[e] = '\0';
	return (trim);
}
// int    main(void)
// {
//     char    s1[] = "eraseUperase";
//     char    set[] = "erase";
//     char    *cpy;

//     cpy = ft_strtrim(s1, set);
//     printf("%s\n", cpy);
//     free(cpy);
//     return (0);
// }
