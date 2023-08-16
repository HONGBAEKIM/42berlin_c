/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:00:52 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 10:52:20 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_utils.h"

int	is_builtin(t_list *tokens)
{
	int		check;
	char	*program_name;

	program_name = tokens->data;
	if (ft_strcmp(program_name, "exit") == 0)
		check = 1;
	else if (ft_strcmp(program_name, "echo") == 0)
		check = 1;
	else if (ft_strcmp(program_name, "env") == 0)
		check = 1;
	else if (ft_strcmp(program_name, "cd") == 0)
		check = 1;
	else if (ft_strcmp(program_name, "pwd") == 0)
		check = 1;
	else if (ft_strcmp(program_name, "export") == 0)
		check = 1;
	else if (ft_strcmp(program_name, "unset") == 0)
		check = 1;
	else
		check = 0;
	return (check);
}

char	**convert_list_to_arr(t_list *lst)
{
	char	**strs;
	int		i;
	int		len;

	i = 0;
	len = ft_lstsize(lst);
	strs = ft_calloc(len + 1, sizeof(char *));
	while (i < len)
	{
		strs[i++] = (char *)lst->data;
		lst = lst->next;
	}
	return (strs);
}

int	has_relative_path(char *first_token)
{
	int	check;

	if (*first_token == '.')
		check = 1;
	else
		check = 0;
	return (check);
}

int	has_absolute_path(char *first_token)
{
	int	check;

	if (*first_token == '/')
		check = 1;
	else
		check = 0;
	return (check);
}
