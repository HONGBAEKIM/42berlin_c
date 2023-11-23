# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 19:24:58 by hongbaki          #+#    #+#              #
#    Updated: 2023/11/21 13:53:10 by hongbaki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
CC = c++
CFLAGS = -Wall -Wextra -Werror

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