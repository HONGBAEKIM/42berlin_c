/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:19:36 by rtimsina          #+#    #+#             */
/*   Updated: 2023/08/11 11:00:43 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*new_lst;
	t_list	*tmp;

	new_lst = 0;
	while (lst)
	{
		tmp = ft_lstnew(lst->data);
		if (!tmp)
			return (0);
		ft_lstadd_back(&new_lst, tmp);
		lst = lst->next;
	}
	return (new_lst);
}

void	ft_lstdel_int(void *data)
{
	(void)data;
}
