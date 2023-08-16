/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:18:21 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/08 10:18:21 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	catch_sigint(int signum)
{
	(void)signum;
	ft_putstr_fd("\n", 1);
}

void	catch_sigquit(int signum)
{
	(void)signum;
	printf("Quit: 3\n");
	kill(0, SIGCHLD);
}
