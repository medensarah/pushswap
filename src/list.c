#include "../ft_printf/ft_printf.h"
#include "pushswap.h"

t_list	*create_node(int nbr)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if(!new)
		return (NULL);
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}


void	lst_addback(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!lst || !new)
		return ;
	ptr = *lst;
	while (*lst && (*lst)->next)
		*lst = (*lst)->next;
	if (*lst)
	{
		(*lst)->next = new;
		*lst = ptr;
	}
	else
		*lst = new;
}

