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

//Depend on where "pid = fork();" is located, print out different. 

//1)Before fork I was one
// After fork I became two
// Before fork I was one\n 
// After fork I became two

//2)Before fork I was one
// After fork I became two
// After fork I became two

//3)Before fork I was one
// After fork I became two

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t   pid;

    //1)pid = fork();
    printf("Before fork I was one\n");
    //2)pid = fork();
    printf("After fork I became two\n");
    //3)pid = fork();
    return 0;
}
