/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:00:53 by hongbaki          #+#    #+#             */
/*   Updated: 2023/04/18 16:00:54 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *p_function(void * data);

int main(void)
{
  pthread_t pthread;
  int thr_id;
  int status;
  char p1[] = "thread_created";
  char p2[] = "thread_main";

  thr_id = pthread_create(&pthread, NULL, p_function, (void*)p1);
  if(thr_id < 0)
  {
    perror("pthread0 create error");
    exit(EXIT_FAILURE);
  }

  p_function((void *)p2);
  //p_function((void *)p1);

  //printf("created thread id: %lx\n", pthread);
  //printf("end\n");
  return 0;
}

void *p_function(void * data)
{
  pthread_t tid; // thread id

  tid = pthread_self();

  char* thread_name = (char *)data;
  int i = 0;

  while(i < 2)
  {
    printf("thread name : %s, tid : %x\n", thread_name, (unsigned int)tid);
    i++;
    usleep(1000 * 1000);
  }
}
