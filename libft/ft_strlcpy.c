/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:28:43 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/11 14:28:45 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strlcpy() function returns the total length of the string
that would have been copied if there was unlimited space

strlcpy() takes the full size of the buffer,
not only the length,
and terminate the result with NUL as long as is greater than 0.
Inlude a byte for the NUL in your value. size size.

strlcpy copies from the string src to end of dest with dest-1
returns with src length
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (!dest || !src)
		return (0);
	i = 0;
	if (!size)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
