/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:58:16 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/21 15:58:17 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int *len)
{
	long unsigned int	i;
	int					ret;

	ret = 0;
	i = 0;
	if (s == 0)
		ft_putstr("(null)", len);
	else
	{
		while (s[i])
		{
			ret = ft_putchar(s[i], len);
			if (ret < 0)
				return (ret);
			i++;
		}
	}
	return (ret);
}
