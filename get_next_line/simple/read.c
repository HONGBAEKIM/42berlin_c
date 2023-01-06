/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:09:43 by hongbaki          #+#    #+#             */
/*   Updated: 2023/01/04 16:09:44 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//read.c

/*
simple read example
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char    buf[100];

    fd = open("./text.txt", O_RDONLY);
    if (fd == -1)
        printf("file open error");
    else
    {
        read(fd, buf, sizeof(buf));
        printf("%s", buf);
        close(fd);
    }
    return (0);
}