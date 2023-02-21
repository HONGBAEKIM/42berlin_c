/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:00:15 by hongbaki          #+#    #+#             */
/*   Updated: 2023/01/20 09:00:16 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

//https://www.codequoi.com/en/creating-and-killing-child-processes-in-c/
//Parent and Child Processes

int main()
{
    pid_t   pid;

    pid = fork();
    if (pid == -1)
        printf("pid == -1 : %d\n", pid);
    if (pid == 0)
        printf("pid == 0 : I'm the child, my internal pid is %d\n", pid);
    if (pid > 0)
        printf("pid > 0 : I'm the parent, my chile's pid is %d\n", pid);
    return (0);
}