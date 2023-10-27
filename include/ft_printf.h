#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);

void	analyze_string(const char *format, va_list *arg_ptr,
			int *num_of_characters);

void	percentage_switcher(const char *character, va_list *arg_ptr,
			int *num_of_characters);

// number starts here!

void	read_number(va_list *arg_ptr, int *num_of_characters);

// read string

void	print_string(va_list *arg_ptr, int *num_of_characters);

// read pointer

void	print_memory(va_list *arg_ptr, int *num_of_characters);

void	print_hex_for_pointer(void *pointer, int *num_of_characters);

void	print_hex(unsigned long long number, int uppercase,
			int *num_of_characters);

void	read_number_u(unsigned int a, int *num_of_characters);

void	print_character(va_list *arg_ptr, int *num_of_characters);

void	print_percentage(int *num_of_character);

void	print_rest(const char *character, int *num_of_characters);

#endif
