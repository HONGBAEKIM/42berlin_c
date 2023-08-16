/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_err_message.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:18:33 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 11:05:27 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write_err_message.h"

void	write_msh_error(char *err_message)
{
	ft_putstr_fd("msh: ", STDERR_FILENO);
	ft_putstr_fd(err_message, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	write_exec_error(char *exec_name, char *err_message)
{
	ft_putstr_fd(exec_name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(err_message, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	write_msh_exec_error(char *exec_name, char *err_message)
{
	ft_putstr_fd("msh: ", STDERR_FILENO);
	ft_putstr_fd(exec_name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(err_message, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	write_msh_exec_arg_error(char *exec_name, char *arg, char *err_message)
{
	ft_putstr_fd("msh: ", STDERR_FILENO);
	ft_putstr_fd(exec_name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(err_message, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	write_msh_exec_arg_error_nocolon(char *exec_name,
										char *arg,
										char *err_message)
{
	ft_putstr_fd("msh: ", STDERR_FILENO);
	ft_putstr_fd(exec_name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(err_message, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}
