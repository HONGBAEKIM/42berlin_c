/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:30:02 by hongbaki          #+#    #+#             */
/*   Updated: 2023/03/07 14:30:02 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **stack, t_list *new)
{
	if (!stack || !new)
		return ;
	new->next = *stack;
	*stack = new;
}

t_list	*ft_lstlast(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

/*
1) add new address in stack 
2) can not put node in stack so return;
3) search until next is null
once you find null save new address in stack next.
*/
void	ft_lstadd_back(t_list **stack, t_list *new)
{
	t_list	*tmp;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	if (!stack || !new)
		return ;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int	ft_lstsize(t_list *head)
{
	size_t	i;
	t_list	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
