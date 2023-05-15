/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:51:42 by hongbaki          #+#    #+#             */
/*   Updated: 2023/05/15 12:51:43 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//1.using readline to read command
//2. check if there is error in command
//3. tokenizing
//4. execute
//5. hmm??

# include "minishell.h"

void    sig_handler(int signum)
{
    if (signum == SIGINT)
        printf("nanoshell$ \n");
    printf("ctrl + c\n");
    rl_on_new_line();//to execute rl_redisplay()
    rl_replace_line("", 1);//replaces the string of the prompt to string.
    rl_redisplay();//reprints the string you put in as an argument
}

void    setting_signal()
{
    signal(SIGINT, sig_handler);// Ctrl + c
    signal(SIGQUIT, SIG_IGN);// Ctrl + /
                            // signal(SIGTERM, sig_handler);
}

//int main(int argc, char **argv, char **envp)
int main()
{
    char *str;

    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ECHOCTL);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    setting_signal();

    while (1)
    {
        str = readline("nanoshell$ ");
        if (!str)
        {
            printf("\033[1A");//raise the cursor one line up
            printf("\033[10C");//maves the cursor forward by 10
            printf(" exit\n");   
            exit(-1);
        }
        else if (*str == '\0')
        {
            free(str);
        }
        else
        {
            add_history(str);
            printf("%s\n", str);
            free(str);
        }
    }
    return (0);
}


