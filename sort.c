/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:00:01 by marvin            #+#    #+#             */
/*   Updated: 2025/10/05 20:00:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sort_init(t_list **stack_a, t_list **stack_b)
{
	int		len_a;
	int		*tab;
	t_list	*tmp;

	len_a = list_len(stack_a);
	tab = malloc(sizeof(int) * len_a);
	if (!tab)
		return (free_fail(stack_a, NULL), 0);
	tmp = *stack_a;
	sort_id(stack_a, tmp, tab, len_a);
	if (len_a <= 5)
		only_five(stack_a, stack_b, len_a);
	else if (len_a <= 100)
		radix_100(stack_a, stack_b);
	else
		radix_500(stack_a, stack_b);
	free(tab);
	tab = NULL;
	return (1);
}

void	sort_id(t_list **stack_a, t_list *tmp, int *tab, int len_a)
{
	int		i;

	i = 0;
	while (tmp)
	{
		tab[i++] = tmp->nbr;
		tmp = tmp->next;
	}
	sort_tab(tab, len_a);
	tmp = *stack_a;
	while (tmp)
	{
    	i = 0;
    	while (i < len_a)
    	{
        	if (tab[i] == tmp->nbr)
        		{
            	tmp->value = i;
            	break;
        	}
        	i++;
    	}
    	tmp = tmp->next;
	}
}

int	list_len(t_list **stack_a)
{
	int		i;
	t_list	*tmp;

	tmp = *stack_a;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	sort_tab(int *tab, int len)
{
    int i;
    int j;
    int tmp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
        while (j < len - i - 1)
		{
			if (tab[j] > tab[j + 1])
            {
				tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
}