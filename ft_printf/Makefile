NAME = libftprintf.a

CC = cc -Wall -Wextra -Werror
AR = ar -crs
RM = rm -f

SRCS = ft_printf.c\
	ft_print_memory.c\
	ft_putchar.c\
	ft_puthex.c\
	ft_putnbr_u.c\
	ft_putnbr.c\
	ft_putstr.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^
# $@ name of the target being generated
# $^ Full list of target

%.o: %.c
	$(CC) -c $< -o $@
# $< the first prerequiste (usually a source file)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus

#a single character
#a string
#address
#decimal number & integer
#unsigned decimal number
#exadecimal (base 16) lowercase & uppercase format
#a percent sign

#va_list = pointer data type for storing the address of a vriable argument.
#		= It’s effectively a pointer to an arguments in the var-args array.

#va_arg = Get the next item in a list of variable arguments
#va_arg(*a, int) =  ap points next factor or int and return one before next factor

#va_start = initialises a pointer of a type va_list to the first variable argument address
#va_start(ap, str) = ap points next the str

#va_end = initialises the variable argument list pointer to NULL
#va_end(ap) = ap is initialised