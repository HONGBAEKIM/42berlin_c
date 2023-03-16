NAME = push_swap
# CHECK = checker

SRCS = check.c\
		etc.c\
		index.c\
		push_swap.c\
		radix.c\
		simple.c\
		simple2.c\
		t_list.c\
		functions_push.c\
		functions_swap.c\
		functions_rotate.c\
		functions_reverserotate.c\

# CHECK_SRCS = check.c\
# 		etc.c\
# 		index.c\
# 		t_list.c\
# 		functions.c\
# 		checker.c\

OBJS = $(SRCS:.c=.o)
# CHECK_OBJS = $(CHECK_SRCS:.c=.o)

CC = cc -Wall -Wextra -Werror

all: $(NAME) #$(CHECK)

$(NAME): $(OBJS)
		make -C libft
		$(CC) $(OBJS) libft/libft.a -o $(NAME)

# $(CHECK): $(CHECK_OBJS)
# 		$(CC) $(CHECK_OBJS) libft/libft.a -o $(CHECK)

clean:
		make clean -C libft
		rm -f $(OBJS)
#rm -f $(CHECK_OBJS)

fclean: clean
		make fclean -C libft
		rm -f $(NAME)
#rm -f $(CHECK)

re: fclean all

.PHONY: all clean fclean re
