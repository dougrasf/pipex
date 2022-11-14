FLAG = -Wall -Wextra -Werror

NAME = pipex

INC = -I ./include

SRC =	./src/main.c \
		./src/error.c \
		./src/fork.c \

LIBFTPATH = ./libft

LIBFT = ./libft/libft.a

CC = cc

all: $(NAME)

${NAME}: ${OBJS}
	make -C ${LIBFTPATH}
	$(CC) $(SRC) $(LIBFT) $(FLAG) $(INC) -o $(NAME)

clean:
	make fclean -C ${LIBFTPATH}

rmv:
	rm -f $(NAME)

fclean: clean
	rm pipex

re: fclean all

refast: rmv all
.PHONY: all clean fclean re