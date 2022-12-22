/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:10:12 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/21 18:10:13 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	puthex_u(unsigned long a, int *len)
{
	int	ret;

	ret = 0;
	if (a < 16)
	{
		ret = ft_putchar("0123456789abcdef"[a % 16], len);
		if (ret < 0)
			return (ret);
	}
	else if (a >= 16)
	{
		puthex_u(a / 16, len);
		ret = ft_putchar("0123456789abcdef"[a % 16], len);
	}
	return (ret);
}

int	ft_print_memory(void *addr, int *len)
{
	char	*str;
	int		ret;

	ret = 0;
	str = (char *)addr;
	ret = ft_putstr("0x", len);
	ret = puthex_u((unsigned long)str, len);
	return (ret);
}
