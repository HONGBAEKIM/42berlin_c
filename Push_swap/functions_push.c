/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:50:07 by hongbaki          #+#    #+#             */
/*   Updated: 2023/03/16 16:50:08 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (ft_lstsize(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}

/* int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (ft_lstsize(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	ft_printf("0.head_from %d\n",head_from);
	ft_printf("0.*stack_from %d\n",*stack_from);
	tmp = head_from;
	head_from = head_from->next;
	ft_printf("1.head_from %d\n",head_from);
	ft_printf("1.tmp %d\n",tmp);
	ft_printf("1.*stack_from %d\n",*stack_from);
	*stack_from = head_from;
	ft_printf("2.head_from %d\n",head_from);
	ft_printf("2.*stack_from %d\n",*stack_from);
	ft_printf("2.head_to %d\n",head_to);
	if (!head_to) //pb
	{
		head_to = tmp;
		ft_printf("3.head_to %d\n",head_to);
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else //pa
	{
		tmp->next = head_to;
		ft_printf("4.head_to %d\n",head_to);
		*stack_to = tmp;
	}
	return (0);
} */