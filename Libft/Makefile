NAME =	libft.a

SOURCES =	ft_split.c	ft_bzero.c	ft_calloc.c	ft_atol.c	ft_isdigit.c ft_strlcpy.c ft_strlen.c

FLAGS += -Wall -Werror -Wextra

CC = cc

OBJECTS = $(SOURCES:.c=.o)

RM += rm -f

all:	$(NAME)

.c.o:
	${CC} ${FLAGS} -c  $< -o ${<:.c=.o}

$(NAME):	$(OBJECTS)
			ar -r $(NAME) $(OBJECTS) 

clean: 
	$(RM) $(OBJECTS) $(BNS_OBJECTS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
