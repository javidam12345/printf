#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"


int ft_printf(const char *format, ...);

void analyze_string(const char* format,va_list *arg_ptr, int *num_of_characters);

void percentage_switcher(const char* character, va_list *arg_ptr, int *num_of_characters);

// number starts here!

void read_number(va_list *arg_ptr, int *num_of_characters);

// read string

void print_string(va_list *arg_ptr, int *num_of_characters);

// read pointer

void print_memory(va_list *arg_ptr, int *num_of_characters);

void lu_to_hex(unsigned long num, int *mum_of_characters, int is_upper);

void read_number_u(unsigned int a, int *num_of_characters);

#endif
