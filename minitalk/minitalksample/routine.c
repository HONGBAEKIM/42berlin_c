/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:34:18 by hongbaki          #+#    #+#             */
/*   Updated: 2023/01/20 10:34:19 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//https://www.codequoi.com/en/creating-and-killing-child-processes-in-c/
//Memory Duplicated but Not Shared

/* after the child process’ creation, the parent doubles 
the value of the given number using a memory address pointer.
But the child prints the number’s original value, 
unaware of the parent’s modification.

after complie below will be output
---------------------------------------------
Before fork, the number is 42
Parent: I'm the parent. PID received from fork = 19418
Parent: The number is 42
Parent: The modified number is 84
Child: I'm the child. PID received from fork = 0
Child: The number is 42 
-----------------------------------------------
*/


void    child_routine(pid_t pid, int *nb)
{
    printf("Child: I'm the child. PID received from fork = %d\n", pid);
    printf("Child: The number is %d\n", *nb);
}

void    parent_routine(pid_t pid, int *nb)
{
    printf("Parent: I'm the parent. PID received from fork = %d\n", pid);
    printf("Parent: The number is %d\n", *nb);
    *nb *= 2;
    printf("Parent: The modified number is %d\n", *nb);
}

int main()
{
    pid_t   pid;
    int nb;

    nb = 42;
    printf("Before fork, the number is %d\n", nb);
    pid = fork();
    if (pid == -1)
        return (EXIT_FAILURE);
    else if (pid == 0)
        child_routine (pid, &nb);
    else if (pid > 0)
        parent_routine (pid, &nb);
    return (EXIT_SUCCESS);
}