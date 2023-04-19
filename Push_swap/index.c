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

	//below 2 lines is initialized what is head 
	index = 0;
	head = get_next_min(stack);
	//after initializing head, using while loof to initialize index from 0 and increment by 1.
	/*
	ex) if I put 5, -1, 1
	  then printf("1. %d\n", head->index); is going to be
		1. 0
		1. 1
		1. 2
	*/ 
	while (head)
	{
		head->index = index++;
		//printf("1. %d\n", head->index);
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