/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:23:45 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/13 10:25:13 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
(*f) = name of function
(unsigned int, char) =  two parameter

Applies the function 'f' to each character of the string 's'
to create a new string with malloc

resulting form successive application of 'f'
*/
char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	len;
	unsigned int	i;

	if (!str || !f)
		return (0);
	len = ft_strlen(str);
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (0);
	i = 0;
	while (str[i])
	{
		newstr[i] = f(i, str[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
/*
char f(unsigned int i, char c)
{
    if (i + 1)
    {
        if (ft_isalpha(c))
            c = c - 32;
    }
    return (c);
}

int	main()
{
    char    *str = "hello world";
    printf("%s\n", ft_strmapi(str, f));
    return (0);
}
*/
