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
/*
int main()
{
    const char    *str = "a";
    int c1 = 'a';
    int c2 = 'c';
    int c3 = '\0';
    int c4 = 'i';

    char * result1 = ft_strchr(str, c1);
    char * result2 = ft_strchr(str, c2);
    char * result3 = ft_strchr(str, c3);
    char * result4 = ft_strchr(str, c4);

    printf("1. %s\n", result1);
    printf("2. %s\n", result2);
    printf("3. %s\n", result3);
    printf("4. %s\n", result4);
    return (0);
}*/
