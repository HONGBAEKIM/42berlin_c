/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:55:03 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/14 13:05:55 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment_utils.h"

int	is_env_var(char *potential_var, t_list *env)
{
	int		i;
	char	*env_str;

	while (env)
	{
		i = 0;
		env_str = (char *)env->data;
		while (potential_var[i] && env_str[i]
			&& (potential_var[i] == env_str[i]))
			i++;
		if ((potential_var[i] == 0 || ft_isspace(potential_var[i]))
			&& (env_str[i] == '=' || env_str[i] == '\0'))
			return (1);
		env = env->next;
	}
	return (0);
}

char	*get_var_name(char *str, t_msh *g_msh)
{
	int		i;
	char	*var;

	i = 0;
	if (str[i] == '$')
		i++;
	while (str[i] && !is_token_delimiter(str[i]) && str[i] != '$'
		&& str[i] != '=' && !is_quote(str[i]) && str[i] != '/')
		i++;
	var = ft_substr(str, 0, i);
	if (!var)
		quit_program(EXIT_FAILURE, g_msh);
	return (var);
}

int	ft_strnstr_iterator(char *haystack, char *needle, size_t len)
{
	size_t	little_len;
	int		iterator;

	iterator = 0;
	little_len = ft_strlen(needle);
	if (little_len == 0)
		return (-1);
	if (len == 0)
		return (-1);
	while (haystack[iterator] && (int)(little_len <= len - iterator))
	{
		if (!ft_strncmp(&haystack[iterator], (char *)needle, little_len))
			return (iterator);
		iterator++;
	}
	return (-1);
}

char	*replace_midstring(char *original,
							char *old_substr,
							char *new_substr,
							int replace_i, t_msh *g_msh)
{
	char	*final;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(original) - ft_strlen(old_substr) + ft_strlen(new_substr);
	final = ft_calloc(len + 1, sizeof(char));
	if (final == 0)
		quit_program(EXIT_FAILURE, g_msh);
	while (*original)
	{
		if (i == replace_i)
		{
			while (new_substr && *new_substr)
				final[i++] = *(new_substr++);
			original += ft_strlen(old_substr);
			replace_i = -2;
		}
		if (*original)
		{
			final[i++] = *(original++);
		}
	}
	final[i] = '\0';
	return (final);
}

/* 
original is input
old_substr can be $HOME,             $?, $USER
new_substr can be /nfs/homes/hongbaki, 0, hongbaki
final should change old_substr to new_substr in middle of input
ex) echo  -nnan"$USER  c $?$HOME" ab
-> -nnanhongbaki   c 0/nfs/homes/hongbaki ab

char	*replace_midstring(char *original,
							char *old_substr,
							char *new_substr,
							int replace_i, t_msh *g_msh)
{
	char	*final;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(original) - ft_strlen(old_substr) + ft_strlen(new_substr);
	final = ft_calloc(len + 1, sizeof(char));
	if (final == 0)
		quit_program(EXIT_FAILURE, g_msh);
	while (*original)
	{
		if (i == replace_i)
		{
			while (new_substr && *new_substr)
				final[i++] = *(new_substr++);
			original += ft_strlen(old_substr);
			//make old_substr empty
			replace_i = -2;
		}
		
		if (*original)
		{
			final[i++] = *(original++);
		}
	}
	final[i] = '\0';
	return (final);
} */

void	tilde_join(char **str, char **home_path, t_msh *g_msh)
{
	char	*temp;

	temp = ft_strjoin(*home_path, &str[0][1]);
	if (!temp)
		quit_program(EXIT_FAILURE, g_msh);
	free(*home_path);
	*home_path = 0;
	free(*str);
	*str = 0;
	*str = temp;
}
