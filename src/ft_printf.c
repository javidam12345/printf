#include "ft_printf.h"


int ft_printf(const char *format, ...)
{
    int num_of_characters = 0;
    va_list arg_ptr;

    va_start(arg_ptr, format);
    analyze_string(format, &arg_ptr, &num_of_characters);
    va_end(arg_ptr);
    return num_of_characters;
}

void analyze_string(const char* format,va_list *arg_ptr, int *num_of_characters)
{
    while (*format != '\0')
    {
        if (*format == '%')
        {
            percentage_switcher(++format, arg_ptr, num_of_characters);
        }
        else
        {
            write(1, format, 1);
            (*num_of_characters)++;
        }
        format++;
    }
}

void percentage_switcher(const char* character, va_list *arg_ptr, int *num_of_characters)
{
    if ((*character == 'd') || (*character == 'i'))
        read_number(arg_ptr, num_of_characters);
    else if (*character == 's')
        print_string(arg_ptr, num_of_characters);
    else if (*character == 'p')
        print_memory(arg_ptr, num_of_characters);
	else if (*character == 'c')
	{
		char c = va_arg(*arg_ptr, int);
		write(1, &c, 1);
		(*num_of_characters)++;
	} 
	else if (*character == 'u')
		read_number_u(va_arg(*arg_ptr, unsigned int), num_of_characters);
	else if (*character == 'x')
		lu_to_hex((unsigned long)va_arg(*arg_ptr, unsigned int), num_of_characters, 0);
	else if (*character == 'X')	
	   	lu_to_hex((unsigned long)va_arg(*arg_ptr, unsigned int), num_of_characters, 1);
}
