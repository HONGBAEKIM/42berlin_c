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

//check below command with another terminal
//ps -eaf | grep -e "zombie_process"

//*parent id of child process changes during execution ot 1
//*child process is removed from process table after execution

//Orphan process
//this is a running process whose parent has finished or terminated.

//Init process
//init is the parent of all processes, executed by the kernel during the booting of the system.
//it has a pid of 1

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t   pid;
	pid_t   ppid;

    pid = fork();
    //printf("Before fork I was one\n");

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

    //printf("After fork I became two\n");

    return 0;
}
