/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:24:51 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/13 15:24:54 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates with malloc and returns a new element

dynamicallyizes a list, puts content, 
and the points to NULL.

Node is represented as a structure that has all the 
necessary date elements to implement a graph.
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	//new->index = -1;
	new->next = 0;
	return (new);
}
