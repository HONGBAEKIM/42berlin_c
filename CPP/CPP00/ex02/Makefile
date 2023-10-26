# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 19:12:31 by hongbaki          #+#    #+#              #
#    Updated: 2023/10/26 14:46:50 by hongbaki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tests
CC = c++
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -std=c++98 -pedantic
SRCS = $(shell find -iname "*.cpp")
#SRCS = phonebook.cpp \
		contact.cpp \
		main.cpp
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