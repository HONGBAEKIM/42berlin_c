/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazzeddi <sazzeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:56:10 by sazzeddi          #+#    #+#             */
/*   Updated: 2022/12/28 13:30:56 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int	main(void)
{
	ft_printf(" %p %p ", 0, 0);
	int	a = 5;
	ft_printf("this is no %d", a);
	return (0);
}
