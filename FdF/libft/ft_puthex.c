/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:19:21 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/21 18:19:22 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
when the c is 'x' then lower case
when the c is 'X' then upper case

Through recursion funtion -> ft_puthex in ft_puthex
*/
int	ft_puthex(int n, char c, int *l)
{
	unsigned int	u;
	int				ret;

	ret = 0;
	u = (unsigned int)n;
	if (u >= 16)
	{
		ft_puthex(u / 16, c, l);
		ft_puthex(u % 16, c, l);
	}
	else
	{
		if (c == 'x')
			ret = ft_putchar("0123456789abcdef"[u % 16], l);
		else
			ret = ft_putchar("0123456789ABCDEF"[u % 16], l);
		if (ret < 0)
			return (ret);
	}
	return (ret);
}
