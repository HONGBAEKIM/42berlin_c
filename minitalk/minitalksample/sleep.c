/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:20:50 by hongbaki          #+#    #+#             */
/*   Updated: 2023/01/20 13:20:52 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

//https://www.codequoi.com/en/creating-and-killing-child-processes-in-c/
//Wait: Stick Around for the Child Processes

int main(void)
{
    pid_t pid;

    pid = fork();
    if (pid == -1)
        return (1);
    if (pid == 0)
    {
        printf("Child: I'm the child, my internal pid is %d.\n", pid);
        sleep(1); // Sleep 1 second.
        printf("Child: Done!\n");
    }
    else if (pid > 0)
    {
        printf("Parent: I'm the parent, my child's pid is %d.\n", pid);
        printf("Parent: Done!\n");
    }
    return (0);
}
