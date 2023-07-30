/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:35:14 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/08 00:56:29 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** A custom shell that takes some basic functionality of bash and history
** management (pressing up / down will parse through commands previously
** entered).
** @param:	- [int] argument count
**			- [char **] argument values
**			- [char **] environment pointers of the shell where the program is
**						running
** Line-by-line comments:
** @1		The command history is a double linked list with a string as data
**			so here input represents a new node of that command history
** @6		The main has an infinite loop so that the program ends only with
**			signals or exit.
** @8		To implement history management we need to have more control on the
**			input of the user. The canonical mode (mode set by default) means
**			that the characters will be read only when the user presses enter.
**			We need to read one input at a time to be able to catch the arrows
**			and other input like the Home key or Ctrl + X.
**			It also means that the keys are "echoed" to the terminal and we
**			don't want to see for instance the ANSI value of the up arrow
** @10		get_input returns a string with the input of the user and takes
**			care of parsing through the history of previous command if the
**			user presses an up or down arrow
** @17		We have to set canonical back on in case the program executed
**			by the user require an input
*/

t_msh	g_msh;

int	main(int argc, char **argv, char **envp)
{
	t_dlist	*input;

	(void)argc;
	(void)argv;
	printf("%s\n", "00.main");
	init_minishell(&g_msh, envp);
	printf("%s\n", "01.main");
	while (1)
	{
		printf("%s\n", "0.main");
		turn_off_canonical_mode(&g_msh.termcaps);
		//this means pressing Enter is not necessary to execute a command

		printf("%s\n", "1.main"); 
		write_prompt();
		//printf("%s\n", "2.main");
	 	input = ft_dlstnew((void *)get_input(g_msh.input_history,
					&g_msh.termcaps));
		printf("%s\n", "3.main");
		if (!input)
			quit_program(EXIT_FAILURE);
		printf("%s\n", "4.main");
		ft_dlstadd_front(&g_msh.input_history, input);
		printf("%s\n", "5.main");
		if (!is_input_valid((const char *)input->data))
			continue ;
		printf("%s\n", "6.main");
		turn_on_canonical_mode(&g_msh.termcaps);
		printf("%s\n", "7.main");
		
		g_msh.ast = get_ast((const char *)input->data);
		printf("%s\n", "8.main");
		exec_ast(g_msh.ast);
		printf("%s\n", "9.main");
		free_ast(g_msh.ast);
		printf("%s\n", "10.main");
		g_msh.ast = 0;
		//printf("%s\n", "11.main");
		// printf("0.strerror(errno) : %s\n", strerror(errno));
		// printf("1.errno : %d\n", errno);

		
	}
	
	return (0);
}
