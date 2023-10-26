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
            (*num_of_characters)++;
            converted /= 10;
        }
    }
}

void read_number_u(unsigned int n, int *num_of_characters) {
	if (n >= 10) 
	{
        read_number_u(n / 10, num_of_characters);
        read_number_u(n % 10, num_of_characters);
    } else 
	{
        ft_putchar_fd('0' + n, 1);
		(*num_of_characters)++;
    }
}

