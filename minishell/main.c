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

//cc -Wall -Wextra -Werror main.c -lreadline 
//; ./a.out

# include "minishell.h"

void    sig_handler(int signum)
{
    if (signum == SIGINT)
    {
        printf("shell$ \n");
        printf("ctrl + c\n");
        rl_on_new_line();//to execute rl_redisplay()
        rl_replace_line("", 0);//Clears the string already entered in the prompt
        rl_redisplay();//makes stop moving prompt cursor 
    }
    if (signum == SIGQUIT)
    {
        printf("ctrl + \\\n");
        /* rl_on_new_line();
        rl_redisplay(); */
        exit(0);
    }
}

void    setting_signal()
{
    signal(SIGINT, sig_handler);// Ctrl + c
    signal(SIGQUIT, sig_handler);// Ctrl + '\'
}

//int main(int argc, char **argv, char **envp)
int main()
{
    char *str;
	struct termios term;


    tcgetattr(STDIN_FILENO, &term);//get the parameters and store them in the termios structure
    //if (ac != 1)
        //error msg int	ft_error(char *str, t_data *data)

    term.c_lflag = term.c_lflag & ~(ECHOCTL);//disable the ECHOCTL(echo control) flag
    
    setting_signal(); //custom function that deals with configuring signal handlers 

    while (1)
    {
        str = readline("shell$ ");
        if (!str)
        {
            printf("exit\n");   
            exit(-1);//terminate the entire program immediately
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
        tcsetattr(STDIN_FILENO, TCSANOW, &term);//set the attributes for a terminal
    }
    return (0);
}

/* 
#include <termios.h>

 termios structure property

struct termios
{
    tcflag_t c_iflag;    // input flags 
    tcflag_t c_oflag;    // output flags 
    tcflag_t c_cflag;    // control flags 
    tcflag_t c_lflag;    // local flags 
    cc_t     c_cc[NCCS]; // control chars 
    speed_t  c_ispeed;   // input speed 
    speed_t  c_ospeed;   // output speed 
};

//printf("\033[6A");//raise the cursor one line down
//printf("\033[10C");// 10 spaces
*/

//'~' means not with bitwise
	//ex)  a = 1010 0101, 
	//    ~a = 0101 1010
