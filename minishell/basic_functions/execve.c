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

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

/* //ex1)
int main(void)
{
    char    *argv[] = {"/bin/ls", "-l", NULL};    

    int val = execve(argv[0], argv, NULL);

    if (val == -1)
        perror("Error");

    printf("Done\n");

    return 0;
} */

//ex2)
int main(void)
{
    pid_t pid;

    char    *argv[] = {"/bin/ls", "-l", NULL};    

    pid = fork();

    if (pid == -1)
        return -1;

    if (pid == 0)
    {        
        printf("1.0 pid : %d\n", pid);
        int val = execve(argv[0], argv, NULL);
        printf("1.1 pid : %d\n", pid);
        if (val == -1)
            perror("Error");
        printf("1.2 pid : %d\n", pid);
    }
    
    else
    {
        printf("2.0 pid : %d\n", pid);
        wait(NULL);
        printf("2.1 pid : %d\n", pid);
        printf("Done\n");
        printf("2.2 pid : %d\n", pid);
    }

    return 0;
}