/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phtread_detach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:50:22 by hongbaki          #+#    #+#             */
/*   Updated: 2023/04/19 20:50:23 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *t_function(void *param)
{
    printf("thread function execution\n");
    for (int i = 1; i <= 5; i++)
    {
        usleep(1000); 
        // Here we go to the main thread..
        // In main, the next instruction is detach, 
        // so the thread is terminated at that point.
        printf("running thread function..%d/5\n",i);
    }
        printf("exit thread function\n");
        return (void *)2147483647;
}

int main()
{
    pthread_t p_thread;
    int thr_id;
    int result;

    thr_id = pthread_create(&p_thread, NULL, t_function, NULL);
    if (thr_id < 0)
    {
        perror("thread create error : ");
        exit(0);
    } 
    pthread_detach(p_thread);

    printf("exit main()\n");

    return 0;
}
