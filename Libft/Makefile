NAME =	libft.a

SOURCES =	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c	ft_isprint.c	ft_strlen.c		ft_memset.c		ft_bzero.c		ft_memcpy.c\
			ft_memmove.c	ft_strlcpy.c	ft_strlcat.c	ft_toupper.c	ft_tolower.c	ft_strchr.c		ft_strrchr.c	ft_strncmp.c	ft_memchr.c\
			ft_memcmp.c		ft_strnstr.c	ft_atoi.c		ft_calloc.c		ft_strdup.c		ft_substr.c		ft_strjoin.c	ft_strtrim.c	ft_itoa.c\
			ft_strmapi.c	ft_striteri.c	ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	ft_split.c		ft_atol.c\

BNS_SOURCES = ft_lstnew.c	ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c	ft_lstclear.c	ft_lstiter.c	ft_lstmap.c\

FLAGS += -Wall -Werror -Wextra

CC = cc

OBJECTS = $(SOURCES:.c=.o)

BNS_OBJECTS = $(BNS_SOURCES:.c=.o)

RM += rm -f

all:	$(NAME)

.c.o:
	${CC} ${FLAGS} -c  $< -o ${<:.c=.o}

$(NAME):	$(OBJECTS)
			ar -r $(NAME) $(OBJECTS) 

bonus:	$(BNS_OBJECTS) $(NAME)
			ar -r $(NAME) $(BNS_OBJECTS)

clean: 
	$(RM) $(OBJECTS) $(BNS_OBJECTS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re