CC= gcc
FLAGS=-Wall -Wextra -Werror
LIBS=-lncurses -L libft/ -lft
INC=-I libft/includes/
SRC=main.c \
	menu.c \
	play4.c \
	print_tools.c

OBJ= $(SRC:.c=.o)
NAME= game_2048

.PHONY: clean fclean re all
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft/
		$(CC) -o $(NAME) $(INC) $(OBJ) $(LIBS)
		echo "\t\xF0\x9F\x8F\x81   Compiling \033[35m$(NAME) \033[0mDONE!"

%.o: %.c
		echo "\t\xF0\x9F\x94\xA7   Building \033[34m $@ \033[0m"
		$(CC) -c $(CFLAGS) $(INC) -o $@ $<

clean:
		echo "\t\xF0\x9F\x92\xA3   Cleaning"
		rm -rf $(OBJ)

fclean: clean
		echo "\t\xF0\x9F\x9A\xBD   Full Clean"
		rm -rf $(NAME)

re: fclean all


