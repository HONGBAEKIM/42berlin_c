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
/*
int  main()
{
    const char     *str = "abcdefgabcdefg";
    int c1 = 'a';
    int c2 = 'b';
    int c3 = '\0';
    int c4 = 'i';
    char * result1 = ft_strrchr(str, c1);
    char * result2 = ft_strrchr(0, c2);
    char * result3 = ft_strrchr(str, c3);
    char * result4 = ft_strrchr(str, c4);

    printf("1. %s\n", result1);
    printf("2. %s\n", result2);
    printf("3. %s\n", result3);
    printf("4. %s\n", result4);
    return (0);
}*/
