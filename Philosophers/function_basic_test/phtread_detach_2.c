/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phtread_detach_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:55:09 by hongbaki          #+#    #+#             */
/*   Updated: 2023/04/19 20:55:10 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//main thread and t_function is running together!!!


void *t_function(void *param)
{
    printf("thread function execution\n");
    for (int i = 1; i <= 5; i++)
    {
        usleep(1000 * 1000 * 2); //wait 2 second 
        printf("%s: ", (char *)param);
        printf("running thread function..%d/5\n",i);
    }
        printf("exit thread function\n");
        return (void *)2147483647;
}

int main()
{
    pthread_t p_thread1;
    pthread_t p_thread2;
    int thr_id1;
    int thr_id2;

    thr_id1 = pthread_create(&p_thread1, NULL, t_function, "thread1");
    thr_id2 = pthread_create(&p_thread2, NULL, t_function, "thread2");
    if (thr_id1 < 0 || thr_id2 < 0)
    {
        perror("thread create error : ");
        exit(0);
    } 
    pthread_detach(p_thread1);
    pthread_detach(p_thread2);
    //  pthread_join(p_thread1, 0);
  //  pthread_join(p_thread2, 0);

    int s = 0;
    while (s < 12)
{
    printf("takes %d\n", s++);
    usleep(1000 * 1000);
}

    printf("exit main()\n");
    return 0;
}
