# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 13:07:12 by hongbaki          #+#    #+#              #
#    Updated: 2023/10/25 10:20:39 by hongbaki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook
#SRCS = $(shell find ./src -iname "*.cpp")
SRCS = phonebook.cpp \
		contact.cpp \
		main.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -std=c++98 -pedantic
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re