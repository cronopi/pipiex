LIB = ar rcs
RM = rm -f

CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c\
ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strjoin.c\
ft_strtrim.c ft_substr.c ft_striteri.c ft_putchar_fd.c ft_split.c ft_strmapi.c ft_putstr_fd.c ft_putnbr_fd.c\
ft_putendl_fd.c ft_itoa.c ft_lstnew.c ft_lstadd_front.c ft_lstlast.c ft_lstsize.c ft_lstadd_back.c\
ft_lstdelone.c ft_lstclear.c ft_lstiter.c get_next_line.c get_next_line_utils.c\
printf/printf.c printf/ft_putstr.c printf/ft_putnbr.c printf/ft_putchar.c printf/ft_itohex.c printf/ft_hex_print.c\
printf/ft_hex_print_void.c printf/ft_ptrtohex.c printf/ft_strlen.c printf/ft_itoa.c printf/ft_print_utoa.c printf/ft_strdup.c

OBJ = $(SRC:.c=.o)
INCLUDE = libft.h

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ) $(INCLUDE)

clean:
	$(RM) $(OBJ) $(BONUSOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
