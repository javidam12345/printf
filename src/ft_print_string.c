#include "ft_printf.h"

void print_string(va_list *arg_ptr, int *num_of_characters)
{
    char* converted;
    converted = va_arg(*arg_ptr, char*);
    (*num_of_characters) += ft_strlen(converted);
    ft_putstr_fd(converted, 1);

}