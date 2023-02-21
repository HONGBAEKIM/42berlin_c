/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:32:21 by hongbaki          #+#    #+#             */
/*   Updated: 2023/01/20 13:32:23 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;

    pid = fork();
    if (pid == -1)
        return (1);
    if (pid == 0)
    {
        printf("Child: I'm the child, my internal pid is %d.\n", pid);
        printf("Child: Done!\n");
    }
    else if (pid > 0)
    {
        printf("Parent: I'm the parent, my child's pid is %d.\n", pid);
        while (1) // Infinite loop, the parent will never end !
            usleep(1);
    }
    return (0);
}
