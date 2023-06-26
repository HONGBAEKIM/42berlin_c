/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:42:49 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/09 14:43:25 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Assigning memory space to store as many variables as size as counts
//initialise the allocated memory space to 0
//malloc dynamically allocates memory
//NULL is returned if memory is insufficient
void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	tmp = malloc(count * size);
	if (!tmp)
		return (tmp);
	ft_bzero(tmp, (count * size));
	return (tmp);
}
