/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:07:12 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/08 11:07:12 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		dst = malloc(sizeof(char));
		if (dst == NULL)
			return (NULL);
		dst[0] = '\0';
		return (dst);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (++i - 1 < len)
		*(dst + i - 1) = *(s + start + i - 1);
	*(dst + i - 1) = '\0';
	return (dst);
} */

/* char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	i = start;
    j = 0;
    while (str[i] && j < len)
    {
        newstr[j] = str[i];
        i++;
        j++;
    }
    newstr[j] = '\0';
    return (newstr);
} */

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (start <= i && j < len)
		{
			newstr[j] = str[i];
			j++;
		}
		i++;
	}
	newstr[j] = '\0';
	return (newstr);
}
