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

/*
if there is error, return -1
if there is no error, return 0; 
*/
int	ft_putstr(char *str, int *len)
{
	long unsigned int	i;
	int					ret;

	ret = 0;
	i = 0;
	if (!str)
		ft_putstr("(null)", len);
	else
	{
		while (str[i])
		{
			ret = ft_putchar(str[i], len);
			if (ret < 0)
				return (ret);
			i++;
		}
	}
	return (ret);
}
