NAME = push_swap

SRCS = push_swap.c

OBJ = $(SRCS.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: 
	cc $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean 
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re