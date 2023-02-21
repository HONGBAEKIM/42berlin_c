/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaltest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:34:58 by hongbaki          #+#    #+#             */
/*   Updated: 2023/01/23 10:34:58 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//https://fkdl0048.github.io/c/42sub_minitalk/

void    Handler(int sig)
{
    printf("Received a signal. exit program.\n signal number %d", sig);
    sleep(1);
    exit(0);
}

int main()
{
    signal(SIGINT, Handler);
    printf("Command : Ctrl+C\n");
    while(1);
}
