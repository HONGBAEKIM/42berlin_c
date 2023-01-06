/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:01:25 by hongbaki          #+#    #+#             */
/*   Updated: 2023/01/04 17:01:28 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
returns
4
5
6
*/

void    increase_num(void)
{
    static int  num = 4;

    printf("%d\n", num);
    num++;
}

int main()
{
    increase_num();
    increase_num();
    increase_num();
    return (0);
}