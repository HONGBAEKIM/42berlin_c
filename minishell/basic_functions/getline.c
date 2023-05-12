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
#include <stdlib.h>

int main(void)
{
    size_t n = 10;
    char *buf = malloc(sizeof(char) * n);

    printf("Enter name ");
    getline(&buf, &n, stdin);

    printf("Name is %sBUFFER SIZE is %ld\n", buf, n);

    free(buf);

    return 0;
}