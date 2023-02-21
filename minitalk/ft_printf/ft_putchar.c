/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:56:02 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/21 15:56:05 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
len++;
if there is error return -1
*/
int	ft_putchar(char c, int *len)
{
	*len = *len + 1;
	return (write(1, &c, 1));
}
