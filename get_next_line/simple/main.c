/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:23:55 by hongbaki          #+#    #+#             */
/*   Updated: 2023/01/03 10:23:57 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	static int	i;
	if (c)
	{
		write (1, &c, 1);
		i++;
	}
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int main()
{
	char s[] = "Hello World\n";
	int y;
	int i;

	i = 0;
	int j = ft_putstr(s);
    printf("\ntotal printed %d\n", j);
	while (s[i] != '\0')
	{
		y = ft_putchar(s[i]);
		i++;
	}
	printf("\ntotal printed %d\n", y);
}
