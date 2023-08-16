/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:44:15 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/19 14:09:57 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*my_dest;
	const char	*my_src;
	size_t		i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	my_dest = dest;
	my_src = src;
	while (i < n)
	{
		my_dest[i] = my_src[i];
		i++;
	}
	return (my_dest);
}
