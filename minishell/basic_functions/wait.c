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

//check with
//ps -aus | grep -e "wait"

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>



int main(void)
{
    pid_t   pid;

/* child process is created. */
    pid = fork();
 
/* if fork fails */
    if (pid == -1)
    {
        perror("unsuccessful\n");
        return (1);
    }
/* in child process */
    if (pid == 0)
    {
        printf("Child process\n");
    }
/* in parent process */
    else
    {
        wait(NULL);
        sleep(30);
        printf("Parent process\n");
    }

    return 0;
}
