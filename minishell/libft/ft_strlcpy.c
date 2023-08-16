/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:02:59 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/04 12:02:59 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*sav_d;
	const char	*sav_s;
	size_t		n;

	sav_d = dst;
	sav_s = src;
	n = size;
	if (n != 0)
	{
		while (--n != 0)
		{
			*sav_d = *sav_s++;
			if (*sav_d++ == '\0')
				break ;
		}
	}
	if (n == 0)
	{
		if (size != 0)
			*sav_d = '\0';
		while (*sav_s++)
			;
	}
	return (sav_s - src - 1);
}

/* size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	n;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (src_len >= size)
		n = size - 1;
	else
		n = src_len;
	ft_memcpy(dst, src, n);
	dst[n] = '\0';
	return (src_len);
} */
