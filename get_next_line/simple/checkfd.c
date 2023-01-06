/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filedescriptor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:41:45 by hongbaki          #+#    #+#             */
/*   Updated: 2023/01/04 12:44:49 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Let's see the output of the file descriptor with file.c and test.txt 

result was 
FD : 3

What does 3 means?
number 3 assess the 3rd index of the FD table
and go to the file table

1.file descriptor table have file descriptor flag and file table pointer
2.file table have mode and offset of inode table pointer
3.inode table  have info of file such as owner group, access mode(read, write, execution permissoins)
  ,file type, and unique number(inode number, i-number)

what is inode?
As a data structure, it has location of address on the data block disk.
Each inode has a unique inode number and is used to identify files.
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd < 1)
	{
		printf("open() error");
		exit(1);
	}
	printf("FD : %d\n", fd);
	close(fd);
	return (0);
}


