# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 19:12:11 by hongbaki          #+#    #+#              #
#    Updated: 2023/10/20 14:20:50 by hongbaki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
SRCS = megaphone.cpp
CFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	c++ $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all