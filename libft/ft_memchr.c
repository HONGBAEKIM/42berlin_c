/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:02:55 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/08 16:30:14 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
The  memchr()  function  scans  the  initial n bytes of the memory area
pointed to by str for the first instance of c.
*/

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*strnew;
	size_t				i;

	i = 0;
	strnew = str;
	while (i < n)
	{
		if (strnew[i] == (unsigned char)c)
			return ((char *)strnew + i);
		i++;
	}
	return (0);
}
