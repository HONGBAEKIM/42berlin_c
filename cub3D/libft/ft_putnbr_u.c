/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:55:55 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/27 16:55:57 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Return with (num divides 10^p)
everytime l++;
ret to check error
*/
void	put_div(unsigned int num, int p, int *l, int *ret)
{
	unsigned int	rest;
	char			c;

	if (p == 1)
	{
		rest = num % 10;
		c = rest + '0';
		*ret = write(1, &c, 1);
		*l = *l + 1;
	}
	else
	{
		num /= 10;
		put_div(num, p - 1, l, ret);
	}
}

/*power is digit*/
int	ft_putnbr_u(unsigned int n, int *len)
{
	unsigned int	power;
	unsigned int	cp;
	int				ret;

	cp = n;
	power = 1;
	while (cp > 9)
	{
		cp = cp / 10;
		power++;
	}
	while (power)
	{
		put_div(n, power, len, &ret);
		if (ret < 0)
			return (ret);
		power--;
	}
	return (0);
}
