/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:59:13 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 09:59:15 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ECHO_H
# define FT_ECHO_H

# include "main.h"

int	ft_echo(t_list *tokens);
int	has_repeated_char_in_str(char repeat_chr, char *str, unsigned int start);

#endif
