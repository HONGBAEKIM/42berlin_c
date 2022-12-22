/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:30:42 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/11 14:33:07 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Search for a specific character in a string
Return the value of the address of the string that starts with the character
if nothing, null returns 
*/
//strchr finds the first occurence of c in the string pointed to by str

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	find;

	i = 0;
	find = (char)c;
	while (str[i] != '\0')
	{
		if (str[i] == find)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == find)
		return ((char *)str + i);
	return (0);
}
