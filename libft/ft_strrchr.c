/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:20:28 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/11 14:34:33 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strrchr() function finds the last occurrence of 
c(concerted to a character) in string.
If the given character is not found, a NULL pointe is returned.
*/
//strrchr finds the last occurence of c in the string pointed to by str
char	*ft_strrchr(const char *str, int c)
{
	char	*last;
	char	find;
	size_t	i;

	last = (char *)str;
	find = (char)c;
	i = ft_strlen(str);
	while (i > 0)
	{
		if (last[i] == find)
			return (last + i);
		i--;
	}
	if (last[i] == find)
		return (last);
	return (0);
}
