/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:53:35 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/05 13:53:38 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strlcat() function returns the total length of the string
that would have been created if there was unlimited space.

This might or might not be equal to the length of the string
actually created, depending on whether there was enought space.
*/

//strlcat adds from the string src to end of dest with dest-1
//returns with dest length + src length
size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (size <= destlen)
		return (srclen + size);
	while (src[i] != '\0' && (destlen + i) < (size - 1))
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}
