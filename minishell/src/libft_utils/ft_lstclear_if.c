/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_if.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:28:05 by rtimsina          #+#    #+#             */
/*   Updated: 2023/08/11 11:03:25 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

void	ft_lstclear_if(t_list **lst, int (*cmp)(void *), void (*del)(void *))
{
	if (!lst)
		return ;
	while (*lst)
	{
		if (cmp((*lst)->data))
			ft_lstdel_first(lst, del);
		else
			lst = &(*lst)->next;
	}
}
