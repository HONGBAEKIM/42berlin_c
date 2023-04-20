/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:13:13 by hongbaki          #+#    #+#             */
/*   Updated: 2023/04/19 20:13:19 by hongbaki         ###   ########.fr       */
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
        usleep(1000 * 1000);
        printf("running thread function..(%d / 5)\n",i);
    }
        printf("End thread function\n");
        return (void *)2147483647;  // result int
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
    //Waits for the thread identifier p_thread to terminate 
    //and receives the return value after termination.
    pthread_join(p_thread, (void *)&result);
    printf("executed thread join : %d\n", result);

    printf("exit main() \n");

    return 0;
}
