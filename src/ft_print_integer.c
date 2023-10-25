#include "ft_printf.h"

void read_number(va_list *arg_ptr, int *num_of_characters)
{
    int converted;

    converted = va_arg(*arg_ptr, int);
    ft_putnbr_fd(converted, 1);
    if (converted == 0)
        (*num_of_characters)++;
    else {
        while (converted != 0){
            num_of_characters++;
            converted /= 10;
        }
    }
}

