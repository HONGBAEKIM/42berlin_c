/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:05:19 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/21 16:05:20 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int *len)
{
	int	ret;

	ret = 0;
	if (n == -2147483648)
		ret = ft_putstr("-2147483648", len);
	else
	{
		if (n < 0)
		{
			ret = ft_putchar('-', len);
			n = -n;
		}
		if (n > 9)
		{
			ret = ft_putnbr(n / 10, len);
			n = n % 10;
		}
		if (n < 10)
		{
			ret = ft_putchar((n % 10) + '0', len);
			if (ret < 0)
				return (ret);
		}
	}
	return (ret);
}
