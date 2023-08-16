/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:46:52 by rtimsina          #+#    #+#             */
/*   Updated: 2023/08/11 11:04:22 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new)
{
	new->next = *lst;
	new->prev = 0;
	if (*lst)
		(*lst)->prev = new;
	*lst = new;
}
