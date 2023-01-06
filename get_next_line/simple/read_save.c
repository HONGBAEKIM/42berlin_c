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

//read_save.c

/*
To save data, strdup and strcat are here. 
strcat concatenates even if there is lack of space
*/
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER_SIZE 1

int main()
{
    char    buf[BUFFER_SIZE + 1];
    char    *save;
    int fd;
    int temp_read_size = 0;

    fd = open("./text.txt", O_RDONLY);
    if (fd == -1)
        printf("file open error");
    else
    {
        while ((temp_read_size = read(fd, buf, BUFFER_SIZE) > 0))
        {
            buf[temp_read_size] = '\0';
            if(save == NULL)
                save = strdup(buf);
            else
                strcat(save, buf);
        }
        printf("%s", save);
        close(fd);
    }
    return (0);
}


