
NAME = claptrap
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address -pedantic

#SRCS = $(shell find -iname "*.cpp")
SRCS = main.cpp, \
		ClapTrap.cpp

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