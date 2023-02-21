/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signalusertest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:55:57 by hongbaki          #+#    #+#             */
/*   Updated: 2023/01/23 10:55:58 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//https://fkdl0048.github.io/c/42sub_minitalk/

void    sig_usrtest(int sig)
{
    if (sig == SIGUSR1)
        printf("received SIGUSR1\n");
    else if (sig == SIGUSR2)
        printf("received SIGUSR2\n");
}

int main(void)
{
    if (signal(SIGUSR1, sig_usrtest) == SIG_ERR)
        perror("Error\n");
    if (signal(SIGUSR2, sig_usrtest) == SIG_ERR)
        perror("Error\n");
    while(1)
    {
        printf("Waiting..\n");
        sleep(2);
    }
}
