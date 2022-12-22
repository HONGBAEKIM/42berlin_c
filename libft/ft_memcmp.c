/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:39:04 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/07 11:39:08 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The  memcmp()  function  compares  the first n bytes
(each interpreted as unsigned char) of the memory areas s1 and s2.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*news1;
	const unsigned char	*news2;
	size_t				i;

	i = 0;
	news1 = s1;
	news2 = s2;
	while (i < n)
	{
		if (*(news1 + i) != *(news2 + i))
			return (*(news1 + i) - *(news2 + i));
		i++;
	}
	return (0);
}
