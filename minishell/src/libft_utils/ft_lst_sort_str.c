/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:19:12 by rtimsina          #+#    #+#             */
/*   Updated: 2023/08/11 11:04:58 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

static void	split_list(t_list *head, t_list **first_half, t_list **last_half)
{
	t_list	*fast;
	t_list	*slow;

	slow = head;
	fast = head->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*first_half = head;
	*last_half = slow->next;
	slow->next = NULL;
}

static t_list	*merge_sort(t_list *a, t_list *b, int (*op)(char *, char *))
{
	t_list	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (op((char *)a->data, (char *)b->data) < 0)
	{
		result = a;
		result->next = merge_sort(a->next, b, op);
	}
	else
	{
		result = b;
		result->next = merge_sort(a, b->next, op);
	}
	return (result);
}

void	ft_lst_sort_str(t_list **lst, int (*op)(char *, char *))
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *lst;
	if (head == NULL || head->next == NULL)
		return ;
	split_list(head, &a, &b);
	ft_lst_sort_str(&a, op);
	ft_lst_sort_str(&b, op);
	*lst = merge_sort(a, b, op);
}
