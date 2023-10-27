NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/
LIBFT_LIB = libft/libft.a

INCLUDES = -I include/

SRC = src/ft_printf.c \
	src/ft_print_integer.c \
	src/ft_print_pointer.c \
	src/ft_print_string.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ)
	cp $(LIBFT_LIB) $(NAME)
	ar rcs $(NAME) $(OBJ)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
