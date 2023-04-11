/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:56:35 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/27 16:56:37 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Through recursion puthex_u in the puthex_t
 to find remainder with output hexadecimal 
*/
int	puthex_u(unsigned long a, int *len)
{
	int	ret;

	ret = 0;
	if (a >= 16)
	{
		puthex_u(a / 16, len);
		puthex_u(a % 16, len);
	}
	else
	{
		ret = ft_putchar("0123456789abcdef"[a % 16], len);
		if (ret < 0)
			return (ret);
	}
	return (ret);
}

/*
to print out address at first ft_putstr("0x") 
and print out left over hexadecimal (16 digit)
*/
int	ft_print_memory(void *addr, int *len)
{
	char	*str;
	int		ret;

	ret = 0;
	str = (char *)addr;
	if (addr == 0)
		ret = ft_putstr("(nil)", len);
	else
	{
		ret = ft_putstr("0x", len);
		ret = puthex_u((unsigned long long)str, len);
	}
	return (ret);
}
