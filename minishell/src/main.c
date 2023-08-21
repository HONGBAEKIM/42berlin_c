/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:14:15 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/21 16:02:26 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	g_code_exit = 0;

int	exit_minishell(void)
{
	write_msh_error("too many arguments");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	t_dlist	*input;
	t_msh	*g_msh;

	g_msh = (t_msh *)malloc(sizeof(t_msh));
	if (argc != 1)
		exit_minishell();
	(void)argv;
	init_minishell(envp, g_msh);
	while (1)
	{
		turn_off_canonical_mode(&g_msh->termcaps, g_msh);
		write_prompt();
		input = ft_dlstnew((void *)get_input(g_msh->input_history,
					&g_msh->termcaps, g_msh));
		if (!input)
			quit_program(EXIT_FAILURE, g_msh);
		ft_dlstadd_front(&g_msh->input_history, input);
		if (!is_input_valid((const char *)input->data, g_msh))
			continue ;
		turn_on_canonical_mode(&g_msh->termcaps, g_msh);
		g_msh->ast = get_ast((const char *)input->data, g_msh);
		exec_ast(g_msh->ast, g_msh);
		free_ast(g_msh->ast);
		g_msh->ast = 0;
	}
	free_msh(g_msh);
	return (0);
}
