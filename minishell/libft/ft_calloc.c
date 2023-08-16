/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:43:30 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/19 16:43:23 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*dst;
	unsigned int	total;
	unsigned int	i;

	total = nmemb * size;
	if (nmemb != 0 && size != 0 && total / nmemb != size)
		return (NULL);
	dst = malloc(total);
	if (!dst)
		return (0);
	i = 0;
	while (total--)
	{
		dst[i] = 0;
		i++;
	}
	return ((void *)dst);
}
