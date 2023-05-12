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

#include <stdio.h>
#include <unistd.h>

int main()
{
    int a = 3;
    int b = 5;
    int sum = a + b;
    pid_t pid;

    pid = getpid();

    printf("sum is %d\n", sum);
    printf("pid is %d\n", pid);

    return (0);
}
