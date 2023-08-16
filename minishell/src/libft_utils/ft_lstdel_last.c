/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:13:39 by ramesh            #+#    #+#             */
/*   Updated: 2023/08/11 11:01:38 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

void	ft_lstdel_last(t_list *lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*last_node;

	if (!lst || !lst->next)
		return ;
	tmp = lst;
	while (tmp->next->next)
		tmp = tmp->next;
	last_node = tmp->next;
	tmp->next = 0;
	del(last_node->data);
	free(last_node);
}
