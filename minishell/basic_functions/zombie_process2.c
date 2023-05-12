/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:29:06 by hongbaki          #+#    #+#             */
/*   Updated: 2023/05/11 13:29:07 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t   pid;
    pid_t   ppid;


    pid = fork();


    if (pid == -1)
    {
        perror("unsuccessful\n");
        return (1);
    }

    if (pid == 0)
    {
        sleep(40);
        printf("I am the child\n");
    }
    else
    {
        ppid = getpid();
        printf("Parent pid is: %u\n", ppid);
    }
    //printf("1. I am the one.\n");

    return 0;
}
