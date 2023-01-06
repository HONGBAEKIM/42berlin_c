/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:58:37 by hongbaki          #+#    #+#             */
/*   Updated: 2023/01/04 13:58:57 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
So Can I change file descriptor?
Let's duplicate one of the number.

result was
fd : 3
fd2 : 4
fd2 : dup(fd)
fd : 3
fd2 : 5


fd is assigned as 3, fd2 is assigned as 4

duplicated fd to fd2, fd2 is assigend as 5
because 3 and 4 are already assigend
Using dup function creates file descriptor. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	int	fd;
    int	fd2;

	fd = open("test.txt", O_RDONLY);
    fd2 = open("test.txt", O_RDONLY);
	if (fd < 1 || fd2 < 1)
	{
		printf("open() error");
		exit(1);
	}
	printf("fd : %d\n", fd);
    printf("fd2 : %d\n", fd2);

    printf("fd2 : dup(fd)\n");
    fd2 = dup(fd);

    printf("fd\t : %d\n", fd);
    printf("fd2\t : %d\n", fd2);

	close(fd);
    close(fd2);
	return (0);
}