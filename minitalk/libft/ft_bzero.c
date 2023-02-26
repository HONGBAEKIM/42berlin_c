/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:50:23 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/11 13:50:25 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The bzero() function places n zero-valued bytes
in the area pointed to by str.

Parameters void    ft_bzero(void *str, size_t n)
    *str
        pointer to the block of memory to fill
    n
		This is number of bytes to be set to the value.
*/
void	ft_bzero(void *str, size_t n)
{
	size_t				i;
	unsigned char		*newstr;

	newstr = str;
	i = 0;
	while (i < n)
	{
		newstr[i] = 0;
		i++;
	}
}
/*int main(void)
{
    char    check[27] = "abcdefghijklmnopqrstuvwxyz";
    char    ft_check[27] = "abcdefghijklmnopqrstuvwxyz";
    int i;
    int j;

    i = 0;
    j = 0;
    bzero(check, 20);
    ft_bzero(ft_check, 20);
    while (i < 27)
    {
        printf("%d", check[i]);
        i++;
    }
    printf("\n");
    while (j < 27)
    {
        printf("%d", ft_check[j]);
        j++;
    }
    printf("\n");
    return (0);
} */
