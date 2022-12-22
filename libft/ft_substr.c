/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:42:38 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/11 15:47:34 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Copies len of str from start position to where the new memory has been allocated
*/

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
