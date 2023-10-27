NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I include/ -I libft/
LIBFT = libft/
LIBFT_LIB = libft/libft.a
AR = ar rcs

SRC = src/ft_printf.c src/ft_print_pointer.c src/ft_print_string.c src/ft_utils.c src/ft_print_integer.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp $(LIBFT_LIB) $(NAME)
	@$(AR) $(NAME) $(OBJ)
	
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	@$(RM) $(NAME) $(LIBFT_LIB)

re: fclean all

.PHONY: all clean fclean re
