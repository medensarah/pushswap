/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:12:41 by smedenec          #+#    #+#             */
/*   Updated: 2025/10/04 17:18:46 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <string.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>

# include "ft_libft/ft_libft.h"
# include "ft_printf/ft_printf.h"

# define GREEN		"\033[0;38;2;142;194;121m"
# define LIGREEN	"\033[0;38;2;142;255;105m"
# define RED		"\033[0;38;2;235;76;76;49m"
# define LIRED		"\033[0;38;2;247;14;21;49m"
# define NONE		"\033[0m"

typedef struct s_list {
	int				nbr;
	int				value;
	struct s_list	*next;
}	t_list;

t_list	*create_node(int nbr);
t_list	*init_parsing(int argc, char **argv);
t_list	*build_list(int argc, char **argv, int i);
void	lst_addback(t_list **head, t_list *new);
void	*error(void);
int		diff_nbr(const char *s1, const char *s2);
int		check_list(char **argv);
int		check_double(char **argv);
int		atoi_range(const char *str, int *nbr);
int		check_number(char *str);
void	*free_fail(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list **stack_a);
int		list_len(t_list *lst);

#endif
