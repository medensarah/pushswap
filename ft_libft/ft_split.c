/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:35:53 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/19 21:40:13 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	build_word(char *array, char *s, int len_word, int i)
{
	int	index_char;

	index_char = 0;
	while (len_word--)
	{
		array[index_char++] = s[i++];
	}
	array[index_char] = '\0';
	return (i);
}

static int	len_string(char *s, char c, int i)
{
	int	len_word;

	len_word = 0;
	while ((s[i] != c) && s[i])
	{
		i++;
		len_word++;
	}
	return (len_word);
}

static int	malloc_fail(char **array, int index_word)
{
	if (array[index_word] == NULL)
	{
		while (index_word >= 0)
		{
			free(array[index_word]);
			index_word--;
		}
		free(array);
		return (1);
	}
	return (0);
}

static int	ft_count_words(char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while ((s[i] != c) && s[i])
			i++;
		if ((s[i] == c || !s[i]) && (s[i - 1] != c))
			words++;
		if (!s[i])
			return (words);
		i++;
	}
	return (words);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		index_word;
	int		words;
	char	**array;

	i = 0;
	index_word = 0;
	words = ft_count_words(s, c);
	array = (char **)malloc(sizeof(char *) *(words + 1));
	if (array == NULL)
		return (NULL);
	while (index_word < words)
	{
		while (s[i] && s[i] == c)
			i++;
		array[index_word] = malloc(sizeof(char) *(len_string(s, c, i) + 1));
		if (malloc_fail(array, index_word))
			return (NULL);
		i = build_word(array[index_word++], s, len_string(s, c, i), i);
	}
	array[index_word] = NULL;
	return (array);
}
// int	main(void)
// {
// 	int		i;
// 	char	*simple;
// 	char	**dooble;

// 	i = 0;
// 	simple = "initiation";
// 	dooble = ft_split(simple, 'i');
// 	while (dooble[i])
// 	{
// 		printf("chain %d :%s\n", i, dooble[i]);
// 		i++;
// 	}

// }
