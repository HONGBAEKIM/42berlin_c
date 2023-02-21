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

#include "minitalk_bonus.h"

void	ft_sighandler(int sig, siginfo_t *info, void *s)
{
	static int	bit = 0;
	static int	i = 0;

	(void)info;
	(void)s;
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
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("%d\n", getpid());
	sig.sa_sigaction = ft_sighandler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = 0;
	while (1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause ();
	}
	return (0);
}
