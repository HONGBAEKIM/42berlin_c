/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:16:25 by hongbaki          #+#    #+#             */
/*   Updated: 2023/01/20 14:16:26 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_confirm(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("SIGUSR1, confirm");
	else
		ft_printf("SIGUSR2, confirm");
}

int	ft_atoi(const char *str)
{
	int	neg;
	int	i;
	unsigned long int	val;

	neg = 1;
	i = 0;
	val = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		neg = neg * (-1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		val = val * 10 + str[i] - '0';
		i++;
	}
	return (val * neg);
}

void	ft_send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (((c >> bit) & 1))
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(100);
		bit++;
	}
}

void	ft_send_str(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_send_char(pid, str[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		signal(SIGUSR1, ft_confirm);
		signal(SIGUSR2, ft_confirm);
		pid = ft_atoi(av[1]);
		ft_send_str(pid, av[2]);
	}
	else
	{
		ft_printf("Client Error : (ac != 3)\n");
		return (1);
	}
	return (0);
}
