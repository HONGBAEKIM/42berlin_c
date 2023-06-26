NAME = minishell

SRCS = main.c

OBJS = $(SRCS:.c=.o)

CC = cc -Wall -Wextra -Werror 

DD = -lreadline

all: $(NAME) 

$(NAME): $(OBJS)
		make -C libft
		$(CC) $(OBJS) libft/libft.a $(DD) -o $(NAME)

clean:
		make clean -C libft
		rm -f $(OBJS)


fclean: clean
		make fclean -C libft
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
