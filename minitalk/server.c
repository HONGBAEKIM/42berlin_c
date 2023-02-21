/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:16:34 by hongbaki          #+#    #+#             */
/*   Updated: 2023/01/20 14:16:36 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sighandler(int sig)
{
	static int	bit = 0;
	static int	i = 0;

	//ft_printf("sig %i\n", sig);
	if (sig == SIGUSR1)
	{
		i = (1 << bit) | i;
		bit++;
	}
	if (sig == SIGUSR2)
		bit++;
	if (bit == 8)
	{
		write(1, &i, i);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, ft_sighandler);
		signal(SIGUSR2, ft_sighandler);
		pause ();
	}
	return (0);
}

/* 
PID
Every process on the system has a unique process ID number.
This is simply an integer. 
You can get the pid for a process via the getpid system call.

getpid() function returns the process ID
of current process.

signal() takes two arguments
first argument : signal to be handled
Second argument : to be executed when the signal is received

https://chromium.googlesource.com/chromiumos/docs/+/master/constants/signals.md
signumber of 10 is SIGUSR1
signumber of 12 is SIGUSR2

pause() is a function that causes the calling process
to pause its execution until a signal is delivered.
 */