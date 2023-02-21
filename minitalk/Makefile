CC = cc -Wall -Wextra -Werror

all: server client

bonus: server_bonus client_bonus

server: server.o
		make -C ft_printf
		$(CC) server.o ft_printf/libftprintf.a -o server

client: client.o
		make -C ft_printf
		$(CC) client.o ft_printf/libftprintf.a -o client

server_bonus: server_bonus.o
		make -C ft_printf
		$(CC) server_bonus.o ft_printf/libftprintf.a -o server_bonus

client_bonus: client_bonus.o
		make -C ft_printf
		$(CC) client_bonus.o ft_printf/libftprintf.a -o client_bonus

clean:
		make clean -C ft_printf
		rm -f server.o client.o server_bonus.o client_bonus.o

fclean: clean
		make fclean -C ft_printf
		rm -f server client server_bonus client_bonus

re: fclean all

.PHONY: all clean fclean re
