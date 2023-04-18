/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:29:30 by hongbaki          #+#    #+#             */
/*   Updated: 2023/03/07 14:29:30 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		flag;

	min = 0;
	flag = 0;
	head = *stack;
	while (head)
	{
		//-1 was initialized in ft_lstnew
		if ((head->index == -1) && (flag == 0 || head->value < min->value))
		{
			min = head;
			flag = 1;
		}
		head = head->next;
	}
	return (min);
}

void	index_stack(t_list **stack)
{
	t_list	*head;
	int		index;

	//below 2 lines for when index is 0
	index = 0;
	head = get_next_min(stack);
	//after initializing first index using while loof to initialize index by 1 increment. 
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}

/* static t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int	flag;

	min = 0;
	flag = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			ft_printf("             1.head->index : %d\n", head->index);
			if ((head->index == -1) && (flag == 0 || head->value < min->value))
			{
				min = head;
				flag = 1;
			}
			head = head->next;
			ft_printf("    min->value : %d\n", min->value);
		}
	}
	ft_printf("  min : %d\n", min);
	return (min);
}

void	index_stack(t_list **stack)
{
	t_list	*head;
	int	index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		ft_printf("head->index : %d\n", head->index);
		head = get_next_min(stack);
	}
} */