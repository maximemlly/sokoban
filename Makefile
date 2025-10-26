# Makefile

NAME = sokoban

SRCS = main.c \
	board.c \
	random.c 

all: $(NAME)

$(NAME): $(SRCS)
	gcc $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all