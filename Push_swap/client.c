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

#include "minitalk.h"

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

/* void	ft_send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (((c >> bit) & 1))
		{
			kill(pid, SIGUSR1);
			//ft_printf("bit %i\n", bit);
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
		pid = ft_atoi(av[1]);
		ft_send_str(pid, av[2]);
	}
	else
	{
		ft_printf("Client Error : (ac != 3)\n");
		return (1);
	}
	return (0);
} */

/*
kill() system call is used by
the operating system 
to send a discontinuation signal 
to a process, urging it to exit

usleep() function delaying a job until the signal is delivered.
*/
