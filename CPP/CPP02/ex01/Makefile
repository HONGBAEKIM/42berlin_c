# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 19:25:02 by hongbaki          #+#    #+#              #
#    Updated: 2023/11/07 12:20:48 by hongbaki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
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