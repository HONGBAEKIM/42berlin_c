# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 10:02:37 by hongbaki          #+#    #+#              #
#    Updated: 2023/11/14 10:03:30 by hongbaki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animal2
CC = c++

# -std=c++98         : C++ language standard to use
# -g                 : Compiler to generate debugging information in the compiled binary.
# -fsanitize=address : identifying and fixing memory-related bugs in your code.
# -pedantic          : Makes the compiler more strict in enforcing the C++ standard
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address -pedantic

#SRCS = $(shell find -iname "*.cpp")
SRCS = Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		Brain.cpp \
		main.cpp

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