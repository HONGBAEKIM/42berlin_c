CC = cc -Wall -Wextra -Werror

all: server client

server: server.o
		make -C ft_printf
		make -C libft
		$(CC) server.o ft_printf/libftprintf.a libft/libft.a -o server

client: client.o
		make -C ft_printf
		make -C libft
		$(CC) client.o ft_printf/libftprintf.a libft/libft.a -o client

clean:
		make clean -C ft_printf 
		make clean -C libft
		rm -f server.o client.o

fclean: clean
		make fclean -C ft_printf 
		make fclean -C libft
		rm -f server client

re: fclean all

.PHONY: all clean fclean re
