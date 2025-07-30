NAME = push_swap

SRCS = main.c errors.c stack_init.c utils.c command_swap.c command_rotate.c command_rev_rotate.c command_push.c push_swap.c 

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
	@echo "\n------------- OBJECTS REMOVED -------------\n"

fclean: clean
	@make -C Libft fclean
	rm -f $(NAME)
	@echo "\n------------- EXECUTABLES REMOVED -------------\n"

re: fclean all

.PHONY: all clean fclean re