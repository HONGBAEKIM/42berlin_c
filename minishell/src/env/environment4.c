/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:27:50 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 11:39:03 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

void	handle_memory_error(t_list *split_token, t_msh *g_msh)
{
	ft_lstclear(&split_token, free);
	quit_program(EXIT_FAILURE, g_msh);
}

void	hme_with_token_piece(char *token_piece, \
t_list *split_token, t_msh *g_msh)
{
	free(token_piece);
	ft_lstclear(&split_token, free);
	quit_program(EXIT_FAILURE, g_msh);
}
