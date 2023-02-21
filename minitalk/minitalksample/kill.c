/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:53:41 by hongbaki          #+#    #+#             */
/*   Updated: 2023/01/20 13:53:42 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

//https://www.codequoi.com/en/creating-and-killing-child-processes-in-c/
//Example Usage of Kill

// Child process routine:
void    child_routine(void)
{
    printf("\e[36mChild: Hi! I'm a child. I'm in an infinite loop.\e[0m\n");
    while (1) // Infinite loop
        continue;
}

// Parent process routine:
void    kill_and_get_children(pid_t *pid)
{
    int	status;
    int	i;

    printf("Parent: I'm the murderous parent.\n");
    i = 0;
    while (i < 3) // Kill all three children with a signal
    {
        kill(pid[i], SIGKILL);
        i++;
    }
    printf("Parent: I killed all my children! Mwahahaaa!\n");
    i = 0;
    while (i < 3) // Wait for each child and get its exit status
    {
        waitpid(pid[i], &status, 0);
        if (WIFEXITED(status))
            printf("Parent: Child [%d] terminated normally.\n", pid[i]);
        else if (WIFSIGNALED(status))
        {
            printf("Parent: Child [%d] was interrupted.\n", pid[i]);
            if (WTERMSIG(status) == SIGTERM)
                printf("\e[31mParent: Child [%d] got the %d signal, SIGTERM\e[0m\n",
                            pid[i], WTERMSIG(status));
            if (WTERMSIG(status) == SIGKILL)
                printf("\e[31mParent: Child [%d] got the %d signal, SIGKILL\e[0m\n",
                            pid[i], WTERMSIG(status));
        }
        i++;
    }
}

int    main(void)
{
    pid_t    pid[3]; // Store fork's return values
    int      i;

    i = 0;
    while (i < 3) // Create 3 children
    {
        pid[i] = fork(); // Create a child
        if (pid[i] == -1)
            return (EXIT_FAILURE);
        else if (pid[i] == 0)
            child_routine();
        else if (pid[i] > 0)
            printf("Parent: Child #%d created with pid = %d\n", i, pid[i]);
        usleep(1000); // Delay next child's creation
        i++;
    }
    kill_and_get_children(pid);
    return (EXIT_SUCCESS);
}
