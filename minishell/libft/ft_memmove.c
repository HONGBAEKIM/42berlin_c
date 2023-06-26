/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:05:12 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/08 18:05:13 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
src < dest : copy direction is from back
src < dest : copy direction is from front 
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned const char	*s;

	if (!dest || !src)
		return (0);
	i = 0;
	d = dest;
	s = src;
	if (s < d)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
/*
int main(void)
{
	char    src1[] = "hijklmn";
	char    dest1[] = "abcdefg";
	
	ft_memmove(dest1, src1, 5);
	printf("%s\n", dest1);
}
*/
/*
    char    src1[6] = "abcdef";
    char    *dest1 = src1 + 2;

    ft_memmove(dest1, src1, 1);
    printf("%s\n", dest1);

*/
