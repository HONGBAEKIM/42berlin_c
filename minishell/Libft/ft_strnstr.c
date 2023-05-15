/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:34:54 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/11 14:35:33 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Returns str if find is empty
(char*)str + i) is same as  (char*)&str[i]
Returns a pointer to the first character of the string if find is found
Returns NULL if find is not found
*/
char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	if (find[0] == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == find[j] && i + j < len)
		{
			j++;
			if (find[j] == '\0')
				return ((char *)str + i);
		}
		i++;
	}
	return (0);
}
/*
int main()
{
    char    str[] = "Hello world how are you";
    char    *ptr1 = ft_strnstr(str, "wo", 10);
    printf("%s\n", ptr1);
    
    return (0);
}*/
