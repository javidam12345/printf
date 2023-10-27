NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I include/ -I libft/
AR = ar rcs

SRC = src/ft_printf.c src/ft_print_pointer.c src/ft_print_string.c src/ft_utils.c src/ft_print_integer.c src/ft_libft_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re
