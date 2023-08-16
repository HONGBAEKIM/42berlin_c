/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_err_message.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:01:55 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 10:01:57 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE_ERR_MESSAGE_H
# define WRITE_ERR_MESSAGE_H

# include "main.h"

void	write_msh_error(char *err_message);
void	write_exec_error(char *exec_name, char *err_message);
void	write_msh_exec_error(char *exec_name, char *err_message);
void	write_msh_exec_arg_error(char *exec_name, char *arg, char *err_message);
void	write_msh_exec_arg_error_nocolon(char *exec_name,
			char *arg,
			char *err_message);

#endif
