/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:25:59 by hongbaki          #+#    #+#             */
/*   Updated: 2023/01/23 12:26:03 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

t_list		*ft_lstnew(int value);
t_list		*ft_lstlast(t_list *head);
int			ft_lstsize(t_list *head);
void		ft_lstadd_front(t_list **stack, t_list *new);
void		ft_lstadd_back(t_list **stack, t_list *new);
void		printlist(t_list *head);

void		ft_error(char *msg);
void		ft_check_args(int ac, char **av);
int			is_sorted(t_list **stack);
int			get_distance(t_list **stack, int index);
void		free_stack(t_list **stack);
void		ft_free(char **str);
long long	ft_atoll(char *s);
int			is_sorted(t_list **stack);

void		radix_sort(t_list **stack_a, t_list **stack_b);
void		simple_sort_1(t_list **stack_a, t_list **stack_b);
void		simple_sort_2(t_list **stack_a, t_list **stack_b);
void		index_stack(t_list **stack);

int			swap(t_list **stack);
int			sa(t_list **stack_a);
int			sb(t_list **stack_b);
int			ss(t_list **stack_a, t_list **stack_b);
int			push(t_list **stack_to, t_list **stack_from);
int			pa(t_list **stack_a, t_list **stack_b);
int			pb(t_list **stack_b, t_list **stack_a);
int			rotate(t_list **stack);
int			ra(t_list **stack_a);
int			rb(t_list **stack_b);
int			rr(t_list **stack_a, t_list **stack_b);
int			reverserotate(t_list **stack);
int			rra(t_list **stack_a);
int			rrb(t_list **stack_b);
int			rrr(t_list **stack_a, t_list **stack_b);

#endif
