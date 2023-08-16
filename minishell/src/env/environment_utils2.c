/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:56:07 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 10:20:24 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment_utils.h"

char	*get_value_name(char *str, t_msh *g_msh)
{
	int		i;
	int		len;
	char	*value;

	i = 0;
	if (str[i] == '$')
		i++;
	while (str[i] && !is_token_delimiter(str[i]) && str[i] != '$'
		&& str[i] != '=')
		i++;
	i++;
	len = ft_strlen(str) - i;
	value = ft_substr(str, i, len);
	if (!value)
		quit_program(EXIT_FAILURE, g_msh);
	return (value);
}

int	is_token_empty(void *data)
{
	int		check;
	char	*token;

	token = data;
	if (*token == '\0')
		check = 1;
	else
		check = 0;
	return (check);
}

void	unset_oldpwd(t_msh *g_msh)
{
	if (is_env_var("OLDPWD", g_msh->dup_envp) == 0)
		create_environment_var("OLDPWD", &g_msh->dup_envp, g_msh);
	else
		remove_env_value("OLDPWD", g_msh);
}

void	replace_string(char *src, char **dest, t_msh *g_msh)
{
	char	*temp;

	temp = ft_strdup(src);
	if (temp == 0)
		quit_program(EXIT_FAILURE, g_msh);
	free(*dest);
	*dest = 0;
	*dest = temp;
}

void	increment_shlvl(t_msh *g_msh)
{
	char	*cur_lvl;
	int		lvl_nbr;

	if (is_env_var("SHLVL", g_msh->dup_envp) == 0)
		create_environment_var("SHLVL=1", &g_msh->dup_envp, g_msh);
	else
	{
		cur_lvl = ft_getenv("SHLVL", g_msh);
		lvl_nbr = ft_atoi(cur_lvl);
		lvl_nbr++;
		free(cur_lvl);
		cur_lvl = ft_itoa(lvl_nbr);
		if (cur_lvl == 0)
			quit_program(EXIT_FAILURE, g_msh);
		update_environment_var("SHLVL", cur_lvl, g_msh->dup_envp, g_msh); 
		free(cur_lvl);
	}
}

/* void	increment_shlvl(t_msh *g_msh)
{
	char	*cur_lvl;
	int		lvl_nbr;

	if (is_env_var("SHLVL", g_msh->dup_envp) == 0)
		//if there isn't any SHLVL in duplicate_envp we create a new as SHLVL=1;
		create_environment_var("SHLVL=1", &g_msh->dup_envp, g_msh);
	else
	{
		//if we already have SHLVL in our environment
		//we call the ft_getenv function check the string SHLVL and 
		//at the end we search for '='
		//and get whatever is at the end like (SHLVL=1) we get 1 as string.
		cur_lvl = ft_getenv("SHLVL", g_msh);
		//make that to int.
		lvl_nbr = ft_atoi(cur_lvl);
		//increase shell level
		lvl_nbr++;
		free(cur_lvl);
		//make it a string back
		cur_lvl = ft_itoa(lvl_nbr);
		if (cur_lvl == 0)
			quit_program(EXIT_FAILURE, g_msh);
		//update environment for shell level and free the string.
		update_environment_var("SHLVL", cur_lvl, g_msh->dup_envp, g_msh); 
		free(cur_lvl);
	}
} */
