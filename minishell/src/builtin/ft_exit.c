/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:52:43 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/08 09:52:44 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exit.h"

int	ft_exit(t_list *args, t_msh *g_msh)
{
	char	*arg;

	if (has_only_one_cmd(g_msh))
		ft_putstr_fd("exit\n", STDERR_FILENO);
	if (args == 0 && has_only_one_cmd(g_msh))
		quit_program(g_msh->exit_status, g_msh);
	else if (args == 0 && !has_only_one_cmd(g_msh))
		return (EXIT_SUCCESS);
	arg = args->data;
	if (ft_strisnumber(arg) && args->next != 0)
		write_msh_exec_error("exit", "too many arguments");
	else if (!ft_strisnumber(arg))
	{
		write_msh_exec_arg_error("exit", arg, "numeric argument required");
		if (has_only_one_cmd(g_msh))
			quit_program(EXIT_GENERAL_ERROR, g_msh);
		else
			return (EXIT_GENERAL_ERROR);
	}
	else if (ft_strisnumber(arg) && args->next == 0 && has_only_one_cmd(g_msh))
		quit_program(ft_atoi(arg), g_msh);
	else if (ft_strisnumber(arg) && args->next == 0 && !has_only_one_cmd(g_msh))
		return (ft_atoi(arg));
	return (EXIT_FAILURE);
}
