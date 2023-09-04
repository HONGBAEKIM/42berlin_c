NAME = philo

SRCS = main.c\
		action.c\
		init.c\
		threads.c\
		utils.c\

OBJS = $(SRCS:.c=.o)

CC = cc -Wall -Wextra -Werror# -fsanitize=thread -g

all: $(NAME) 

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean:
		rm -f $(OBJS)


fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
