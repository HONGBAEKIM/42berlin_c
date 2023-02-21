/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:37:29 by hongbaki          #+#    #+#             */
/*   Updated: 2023/01/20 13:37:31 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

//https://www.codequoi.com/en/creating-and-killing-child-processes-in-c/

// Define a macro for a specific child exit code (if we do not
// specify this exit code during compilation with the 
// -D CHILD_EXIT_CODE=[number] option), by default, it will be 42:
#ifndef CHILD_EXIT_CODE
# define CHILD_EXIT_CODE 42
#endif

// Define a macro for the expected exit status
#define EXPECTED_CODE 42

// Child process routine:
void	child_routine(pid_t pid)
{
	printf("\e[36mChild: Hi! I'm the child. PID received from fork = %d\e[0m\n",
			pid);
	printf("\e[36mChild: Exiting with exit code %d.\e[0m\n",
			CHILD_EXIT_CODE);
	exit(CHILD_EXIT_CODE);
}

// Parent process routine:
void	parent_routine(pid_t pid)
{
	int	status;

	printf("Parent: I'm the parent. PID received from fork = %d\n", pid);
	printf("Parent: Waiting for my child with PID [%d].\n", pid);
	waitpid(pid, &status, 0); // Wait for child
	printf("Parent: My child exited with status %d\n", status);
	if (WIFEXITED(status)) // If child exited normally
	{
		printf("Parent: My child's exit code is %d\n",
				WEXITSTATUS(status));
		if (WEXITSTATUS(status) == EXPECTED_CODE)
			printf("Parent: That's the code I expected!\n");
		else
			printf("Parent: I was not expecting that code...\n");
	}
}

int	main(void)
{
	pid_t	pid; // Store fork's return value

	pid = fork(); // Create child process
	if (pid == -1)
		return (EXIT_FAILURE);
	else if (pid == 0) // Child process
		child_routine(pid);
	else if (pid > 0) // Parent process
		parent_routine(pid);
	return (EXIT_SUCCESS);
}
