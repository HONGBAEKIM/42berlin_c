/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:22:17 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/14 09:22:19 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Adds a new node at the end of the list


Different between !lst and !*lst

!lst ====== list doesn't exist 
!*lst ===== An empty list


why ft_lstlast(*lst) instead of ft_lstlast(lst)?

lstlast fundtion takes 
the address of the first element as a parameter t_list *.

The data type of the argument we received from the
ft_lstadd_back function is t_list *,
Since (t_list *) = t_list,
we need to send ft_lstlast(*lst) as the argument.
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
	{
		tmp = tmp->next;
	}	
	tmp->next = new;
}
