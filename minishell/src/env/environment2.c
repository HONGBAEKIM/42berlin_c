/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:57:03 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/14 13:59:49 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

char	*ft_getenv(char *key, t_msh *g_msh)
{
	int		i;
	t_list	*envp;
	char	*curr_envp;
	char	*value;

	envp = g_msh->dup_envp;
	while (envp)
	{
		i = 0;
		curr_envp = (char *)envp->data;
		while (key[i] && curr_envp[i] && (key[i] == curr_envp[i]))
			i++;
		if (!key[i] && (curr_envp[i] == '='
				|| curr_envp[i] == '\0'))
		{
			i++;
			value = ft_strdup(&(curr_envp[i]));
			if (!value)
				quit_program(EXIT_FAILURE, g_msh);
			return (value);
		}
		envp = envp->next;
	}
	return (NULL);
}

/* char	*ft_getenv(char *key, t_msh *g_msh)
{
	//env is used as key and value pair
	//example USER=hongbaki
	//we check through key and return the value after '='
	//if not found return NULL
	int		i;
	t_list	*envp;
	char	*curr_envp;
	char	*value;

	envp = g_msh->dup_envp;
	while (envp)
	{
		i = 0;
		curr_envp = (char *)envp->data;
		//print env all sentance by one line and one line 
		while (key[i] && curr_envp[i] && (key[i] == curr_envp[i]))
			i++;
		if (!key[i] && (curr_envp[i] == '='
				|| curr_envp[i] == '\0'))
		{
			i++;
			value = ft_strdup(&(curr_envp[i]));
			if (!value)
				quit_program(EXIT_FAILURE, g_msh);
			return (value);
		}
		envp = envp->next;
	}
	return (NULL);
} */

void	duplicate_env(t_list **dup_envp, char **envp, t_msh *g_msh)
{
	t_list	*next_env;
	int		i;
	char	*tmp;

	if (!envp || !envp[0])
		quit_program(EXIT_FAILURE, g_msh);
	i = 0;
	while (envp[i] != NULL)
	{
		tmp = ft_strdup(envp[i]);
		if (!tmp)
			quit_program(EXIT_FAILURE, g_msh);
		next_env = ft_lstnew(tmp);
		if (!next_env)
			quit_program(EXIT_FAILURE, g_msh);
		ft_lstadd_back(dup_envp, next_env);
		i++;
	}
}

void	remove_env_value(char	*key, t_msh *g_msh)
{
	int		i;
	t_list	*envp;
	char	*curr_envp;

	envp = g_msh->dup_envp;
	while (envp)
	{
		i = 0;
		curr_envp = (char *)envp->data;
		while (key[i] && curr_envp[i] && (key[i] == curr_envp[i]))
			i++;
		if (!key[i] && curr_envp[i] == '=')
		{
			replace_string(key, &curr_envp, g_msh);
			envp->data = curr_envp;
		}
		envp = envp->next;
	}
	return ;
}

void	replace_status_env(char **str, int last_status, t_msh *g_msh)
{
	int		replace_spot;
	char	*status_string;
	char	*final;

	replace_spot = ft_strnstr_iterator(*str, "$?", ft_strlen(*str));
	while (replace_spot != -1)
	{
		status_string = ft_itoa(last_status);
		if (status_string == 0)
			return (quit_program(EXIT_FAILURE, g_msh));
		final = replace_midstring(*str, "$?", status_string, \
		replace_spot, g_msh);
		free(status_string);
		status_string = 0;
		free(*str);
		*str = final;
		replace_spot = ft_strnstr_iterator(*str, "$?", ft_strlen(*str));
	}
}

int	is_path_executable(char *exec_file)
{
	struct stat	statbuf;

	if (has_absolute_path(exec_file)
		&& (stat(exec_file, &statbuf) == EXIT_SUCCESS
			|| S_ISREG(statbuf.st_mode)))
		return (1);
	else
		return (0);
}
