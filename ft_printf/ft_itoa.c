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

static long	countdigit(long n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	putnbr(long n)
{
	if (n > 9)
		putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int	ft_itoa(int n)
{
	long	l;
	int		size;

	size = 0;
	l = n;
	if (l < 0)
	{
		ft_putchar('-');
		l *= -1;
		size *= 1;
	}
	size += countdigit(l);
	putnbr(l);
	return (size);
}

int	ft_uitoa(int n)
{
	unsigned int	u;
	int				size;

	size = 0;
	u = (unsigned int)n;
	size += countdigit(u);
	putnbr(u);
	return (size);
}
