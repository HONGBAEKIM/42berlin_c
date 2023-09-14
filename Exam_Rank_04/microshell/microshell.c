/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:28:39 by hongbaki          #+#    #+#             */
/*   Updated: 2023/09/14 20:28:27 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : microshell
Expected files   : *.c *.h
Allowed functions: malloc, free, write, close, fork, waitpid, signal, kill, exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp
--------------------------------------------------------------------------------------

Write a program that will behave like executing a shell command

- The command line to execute will be the arguments of this program

- Executable's path will be absolute or relative 
but your program must not build a path (from the PATH variable for example)

- You must implement "|" and ";" like in bash
	- we will never try a "|" immediately followed or preceded by nothing or "|" or ";"

- Your program must implement the built-in command cd only with a path as argument 
(no '-' or without parameters)
	- if cd has the wrong number of argument your program should print in STDERR 
	"error: cd: bad arguments" followed by a '\n'
	- if cd failed your program should print in STDERR 
	"error: cd: cannot change directory to path_to_change" 
	followed by a '\n' with path_to_change replaced by the argument to cd
	- a cd command will never be immediately followed or preceded by a "|"

- You don't need to manage any type of wildcards (*, ~ etc...)

- You don't need to manage environment variables ($BLA ...)

- If a system call, except execve and chdir, 
returns an error your program should immediatly print 
"error: fatal" in STDERR followed by a '\n' and the program should exit

- If execve failed you should print 
"error: cannot execute executable_that_failed" 
in STDERR followed by a '\n' with 
executable_that_failed replaced with the path of the failed executable 
(It should be the first argument of execve)

- Your program should be able to manage more than hundreds of "|" 
even if we limit the number of "open files" to less than 30.

for example this should work:
$>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
microshell
i love my microshell
$>

Hints:
Don't forget to pass the environment variable to execve

Hints:
Do not leak file descriptors!
 */


#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int	err(char *str)
{
	while (*str)
		write(2, str++, 1);
	return 1;
}

int	cd(char **av, int i)
{
	if (i != 2)
		return err("error: cd: bad arguments\n");
	if (chdir(av[1]) == -1)
		return err("error: cd: cannot change directory to "), err(av[1]), err("\n");
	return 0;
}

int	exec(char **av, char **envp, int i)
{
	int	fd[2];
	int status;
	int	has_pipe = av[i] && !strcmp(av[i], "|");

	if (has_pipe && pipe(fd) == -1)
		return err("error: fatal\n");
	
	int	pid = fork();
	if (!pid)
	{
		av[i] = 0;
		if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return err("error: fatal\n");
		execve(*av, av, envp);
		return err("error: cannot execute "), err(*av), err("\n");
	}

	waitpid(pid, &status, 0);
	if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return err("error: fatal\n");

	return WIFEXITED(status) && WEXITSTATUS(status);
}

int	main(int ac, char **av, char **envp)
{
	int	i = 0;
	int status = 0;

	if (ac > 1)
	{
		while (av[i] && av[++i])
		{
			av += i;
			i = 0;
			while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
				i++;
			if (!strcmp(*av, "cd"))
				status = cd(av, i);
			else if(i)
				status = exec(av, envp, i);
		}
	}
	return status;
}




































/* int err(char *str) 
{
    while (*str)
        write(2, str++, 1);
    return 1;
}

int cd(char **argv, int i) 
{
    if (i != 2)
        return err("error: cd: bad arguments\n");
    else if (chdir(argv[1]) == -1)
        return err("error: cd: cannot change directory to "), err(argv[1]), err("\n");
    return 0;
}

int exec(char **argv, char **envp, int i) 
{
    int fd[2];
    int status;
    int has_pipe = argv[i] && !strcmp(argv[i], "|");

    if (has_pipe && pipe(fd) == -1)
        return err("error: fatal\n");

    int pid = fork();
    if (!pid) 
    {
        argv[i] = 0;
        if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
            return err("error: fatal\n");
        execve(*argv, argv, envp);
        return err("error: cannot execute "), err(*argv), err("\n");
    }

    waitpid(pid, &status, 0);
    if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        return err("error: fatal\n");
    return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int argc, char **argv, char **envp) 
{
    int    i = 0;
    int    status = 0;

    if (argc > 1) 
    {
        while (argv[i] && argv[++i]) 
        {
            argv += i;
            i = 0;
            while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
                i++;
            if (!strcmp(*argv, "cd"))
                status = cd(argv, i);
            else if (i)
                status = exec(argv, envp, i);
        }
    }
    return status;
} */

/* 
#ifdef TEST_SH
# define TEST	1
#else
# define TEST	0
#endif

int	ft_putstr_fd2(char *str, char *arg)
{
	while (*str)
		write(2, str++, 1);
	if (arg)
		while (*arg)
			write(2, arg++, 1);
	write(2, "\n", 1);
	return (1);
}

int	ft_execute(char **av, int i, int tmp_fd, char **env)
{
	av[i] = NULL;
	dup2(tmp_fd, STDIN_FILENO);
	close(tmp_fd);
	execve(av[0], av, env);
	return (ft_putstr_fd2("error: cannot execute ", av[0]));
}

int	main(int ac, char **av, char **env)
{
	int	i = 0;
	int	fd[2];
	int	tmp_fd;
	(void)ac;

	tmp_fd = dup(STDIN_FILENO);
	while (av[i] && av[i + 1])
	{
		av = &av[i + 1];
		i = 0;
		while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
			i++;
		if (!strcmp(av[0], "cd"))
		{
			if (i != 2)
				ft_putstr_fd2("error: cd: bad arguments", NULL);
			else if (chdir(av[1]) != 0)
				ft_putstr_fd2("error: cd: cannot change directory to ", av[1]);
		}
		else if (i != 0 && (av[i] == NULL || !strcmp(av[i], ";")))
		{
			if (fork() == 0)
			{
				if (ft_execute(av, i, tmp_fd, env))
					return (1);
			}
			else
			{
				close(tmp_fd);
				while (waitpid(-1, NULL, WUNTRACED) != -1)
					;
				tmp_fd = dup(STDERR_FILENO);
			}
		}
		else if(i != 0 && !strcmp(av[i], "|"))
		{
			pipe(fd);
			if (fork() == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				if (ft_execute(av, i, tmp_fd, env))
					return (1);
			}
			else
			{
				close(fd[1]);
				close(tmp_fd);
				tmp_fd = fd[0];
			}
		}
	}
	close(tmp_fd);
	if (TEST)
		while (1);
	return (0);
} */