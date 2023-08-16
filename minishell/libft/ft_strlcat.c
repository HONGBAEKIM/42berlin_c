/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:14:05 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/04 15:14:05 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*sav_d;
	const char	*sav_s;
	int			n;
	int			length_dst;

	sav_d = dst;
	sav_s = src;
	n = size;
	while (n-- != 0 && *sav_d != '\0')
		sav_d++;
	length_dst = sav_d - dst;
	n = size - length_dst;
	if (n == 0)
		return (length_dst + ft_strlen(sav_s));
	while (*sav_s != '\0')
	{
		if (n != 1)
		{
			*sav_d++ = *sav_s;
			n--;
		}
		sav_s++;
	}
	*sav_d = '\0';
	return (length_dst + sav_s - src);
}

/* size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	slen;
	size_t	dlen;

	i = 0;
	j = 0;
	j = ft_strlen(dst);
	dlen = j;
	slen = ft_strlen(src);
	if (size == 0 || size <= dlen)
		return (slen + size);
	while (src[i] != '\0' && (i < (size - dlen -1)))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dlen + slen);
}
 */