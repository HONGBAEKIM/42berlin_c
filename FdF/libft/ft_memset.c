/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:14:06 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/09 18:15:48 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
memset
    Fill with "len" bytes of "c" the memory of "str"

Parameters *ft_memset(void *str, int c, size_t n)
    *str
        pointer to the block of memory to fill
    c
        this is the value to be set.
		The value is passed as an int.
		but the function fills the block of memory
		using the unsigned char conversion of this value.
    n
		This is number of bytes to be set to the value.

Return
    A pointer to the memory area str

Description
    void * is Just save addressstrlcpy
*/

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*newstr;
	size_t			i;

	i = 0;
	newstr = str;
	while (i < n)
	{
		newstr[i] = c;
		i++;
	}
	return (str);
}
/* You can not dereference with void *str
That is why you need unsigned char to point address

Why unsigned char should be here instead of char?
value saves as unsigned char data (iscii code is 0 to 255)

unsigned char hold a value in the range 0 to 255
while a signed char has the range -128 to 127

The number of bytes
Value c (converted to an unsigned char)
A pointer to the memory area str
*/
/*
int main(void)
{
    char str[] = "Let's see what happen";
    int c = 'a';

    printf("%s\n", str);
    ft_memset(str, c, 5);
    printf("%s\n", str);
	memset(str, c, 5);
    printf("%s\n", str);
    return (0);
}*/
