/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:52:27 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/19 14:27:43 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*my_arr;
	size_t			i;

	my_arr = (unsigned char *)s;
	i = 0;
	while (n > i)
	{
		my_arr[i] = (unsigned char)c;
		i++;
	}
	return (my_arr);
}
