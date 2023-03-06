NAME=libftgnl.a

SRCS= get_next_line.c get_next_line_utils.c

OBJS= $(SRCS:.c=.o)	

CC=gcc

RM= rm -rf

CFLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean: clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re