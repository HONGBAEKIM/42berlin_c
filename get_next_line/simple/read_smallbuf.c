/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:07:30 by hongbaki          #+#    #+#             */
/*   Updated: 2023/01/04 16:07:31 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//read_smallbuf.c

/*
buffer size is 1, file size is 7
What if buffer is smaller than file size?

when the data size is positive, printf using while function
and initialize buffer and again again

*/

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER_SIZE 1

int main()
{
    char    buf[BUFFER_SIZE + 1];
    int fd;
    int temp_read_size = 0;

    fd = open("./text.txt", O_RDONLY);
    if (fd == -1)
        printf("file open error");
    else
    {
        while ((temp_read_size = read(fd, buf, BUFFER_SIZE) > 0))
        {
            printf("%s", buf);
            memset(buf, 0, BUFFER_SIZE);
        }
        close(fd);
    }
    return (0);
}

