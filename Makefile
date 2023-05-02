RM = rm -f

CC = gcc
#FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
FLAGS = -Wall -Wextra -Werror

LIBFT= -L libft -lft

NAME = pipex
SRC = main.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(OBJ) $(FLAGS) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJ) $(BONUSOBJ)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: bonus all clean fclean re
