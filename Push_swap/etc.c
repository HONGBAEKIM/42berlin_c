/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:29:15 by hongbaki          #+#    #+#             */
/*   Updated: 2023/03/07 14:29:16 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(0);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
	free(str);
}

int	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

/* 
Check how far min index from the first position of list.
int get_distance(t_list **stack, int index)
{
	t_list  *head;
	int distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		ft_printf("0.head->index : %d\n", head->index);
		ft_printf("0.distance : %d\n", distance);
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
} */
