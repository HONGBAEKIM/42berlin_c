# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 10:02:37 by hongbaki          #+#    #+#              #
#    Updated: 2023/11/09 11:26:02 by hongbaki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fragtrap
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address -pedantic

SRCS = $(shell find -iname "*.cpp")

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

#superimportant, keep in mind!
#to complie with c++ instead of g++
%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re