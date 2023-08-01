/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_absolute_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:46:03 by dda-silv          #+#    #+#             */
/*   Updated: 2021/05/25 10:30:36 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_absolute_path.h"

/*
** If the program name doesn't have a relative path, then the executable
** probably is in one of the paths of $PATH. We'll return something like /bin/ls
** @param:	- [char *] program to find
** @return:	[char *] program with it's absolute path or a duplicate of the
**					 program name if it wasn't found
** Line-by-line comments:
** @4		Gets NULL-terminated array of strings, each representing one of the
**			paths stored inside $PATH
** @5-10	Edge case: the evaluator doesn't like you and executed "unset PATH"
**			which means that there is nowhere to look for the program. We need
**			to return a duplicate which will trigger a "command not found" error
*/

char	*get_absolute_path(char *program_name)
{
	char	**path_env_split;
	char	*absolute_path;

	// printf("%s\n", "8.4.3.4.0.get_absolute_path");
	path_env_split = get_path_env_split();
	// printf("%s\n", "8.4.3.4.1.get_absolute_path");
	if (!path_env_split)
	{
		// printf("%s\n", "8.4.3.4.2.get_absolute_path");
		absolute_path = ft_strdup(program_name);
		if (!absolute_path)
		{
			// printf("%s\n", "8.4.3.4.3.get_absolute_path");
			quit_program(EXIT_FAILURE);
		}
	}
	else
	{
		// printf("%s\n", "8.4.3.4.4.get_absolute_path");
		absolute_path = get_correct_path(program_name, path_env_split);
		// printf("%s\n", "8.4.3.4.5.get_absolute_path");
		free_arr((void **)path_env_split);
		// printf("%s\n", "8.4.3.4.6.get_absolute_path");
	}
	return (absolute_path);
}

/*
** Gets a NULL-terminated array of strings where each strings represents a path
** from $PATH
** @return:	[char **] paths split into seperate strings and each with a slash at
**					  end so that we only have to append to it the name of the
**					  program we are looking for
** Line-by-line comments:
** @7		In $PATH, each path are separated with ':'
** @11		Some path do have a '/' at the end of the path, but others don't.
**			We are adding it for the ones that don't
*/

char	**get_path_env_split(void)
{
	char	*path_env;
	char	**path_env_split;

	// printf("%s\n", "8.4.3.4.0.0.get_path_env_split");
	path_env = ft_getenv("PATH");
	// printf("path_env : %s\n", path_env);
	// printf("%s\n", "8.4.3.4.0.1.get_path_env_split");
	if (!path_env)
		return (0);
	// printf("%s\n", "8.4.3.4.0.2.get_path_env_split");
	path_env_split = ft_split(path_env, ":");
	// printf("0.path_env_split : %s\n", *path_env_split);
	// printf("%s\n", "8.4.3.4.0.3.get_path_env_split");
	free(path_env);
	if (!path_env_split)
		quit_program(EXIT_FAILURE);
	// printf("%s\n", "8.4.3.4.0.4.get_path_env_split");
	add_slash(&path_env_split);
	// printf("1.path_env_split : %s\n", *path_env_split);
	// printf("%s\n", "8.4.3.4.0.5.get_path_env_split");
	return (path_env_split);
}

/*
** Adds a slash to all paths that aren't terminated with '/'
** @param:	- [char **] NULL-terminated array of strings where each string
**                      represents a path from $PATH
** Line-by-line comments:
** @14		The initial path was allocated in ft_split, so we need to free it
**			before overwritting it with the new_path
*/

void	add_slash(char ***path_env_split)
{
	int		i;
	char	*path;
	int		len;
	char	*new_path;

	i = 0;
	while ((*path_env_split)[i])
	{
		path = (*path_env_split)[i];
		//printf("0.path : %s\n", path);
		len = ft_strlen(path);
		//printf("len : %d\n", len);
		if (path[len - 1] != '/')
		{
			new_path = ft_strjoin(path, "/");
			free(path);
			(*path_env_split)[i] = new_path;
		}
		//printf("1.new_path : %s\n", new_path);
		i++;
	}
}

/*
** Parses all the folders where the executable could be and checks inside
** @param:	- [char *] program we are looking for
**			- [char **] NULL-terminated array of strings where each string
**                      represents a path from $PATH
** @return:	[char *] absolute path of the program we are looking for. Or a
**                   duplicate of the program name if we didn't find
** Line-by-line comments:
** @8-13	We join each path with the program name. If it's the correct one
**			stat() will return EXIT_SUCCESS, we'll break from the loop and we'll
**			return that same absolute path. Else, free memory and try again with
**			another path
** @16-21	If path_env_split[i] is NULL, it means we reaches the end of the
**			array, so we didn't find the program in any of the paths so we
**			return a duplicate of the program name
*/

char	*get_correct_path(char *program_name, char **path_env_split)
{
	char		*absolute_path;
	int			i;
	struct stat	statbuf;

	i = 0;
	// printf("%s\n", "8.4.3.4.4.0.get_correct_path");
	while (path_env_split[i])
	{
		//printf("%s\n", "8.4.3.4.4.1.get_correct_path");
		absolute_path = ft_strjoin(path_env_split[i], program_name);
		//printf("path_env_split[i] : %s\n", path_env_split[i]);
		//printf("absolute_path : %s\n", absolute_path);
		//printf("%s\n", "8.4.3.4.4.2.get_correct_path");
		if (!absolute_path)
		{
			// printf("%s\n", "8.4.3.4.4.3.get_correct_path");
			quit_program(EXIT_FAILURE);
		}
		// printf("(stat(absolute_path, &statbuf) %d\n", (stat(absolute_path, &statbuf)));
		// printf("absolute_path : %s\n", absolute_path);
		if (stat(absolute_path, &statbuf) == EXIT_SUCCESS)
		{
			// printf("%s\n", "8.4.3.4.4.4.get_correct_path");
			break ;
		}
		//printf("%s\n", "8.4.3.4.4.5.get_correct_path");
		free(absolute_path);
		i++;
	}
	if (!path_env_split[i])
	{
		absolute_path = ft_strdup(program_name);
		if (!absolute_path)
			quit_program(EXIT_FAILURE);
	}
	return (absolute_path);
}
