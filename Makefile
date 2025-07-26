NAME = push_swap

SRCS = push_swap.c errors.c node_init.c swap_stack.c

OBJ = $(SRCS:.c=.o)

CFLAGS += -Wall -Werror -Wextra

LIBFT = ./Libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@cd Libft && make 
	@cc $(OBJ) $(CFLAGS) $(LIBFT) -o $(NAME)
	@echo "\n------------- COMPILATION DONE -------------\n"


clean:
	@make -C Libft clean
	rm -f $(OBJ)
	@echo "\n------------- REMOVED OBJECTS -------------\n"

fclean: clean
	@make -C Libft fclean
	rm -f $(NAME)
	@echo "\n------------- REMOVED	 EXECUTABLES -------------\n"

re: fclean all

.PHONY: all clean fclean re