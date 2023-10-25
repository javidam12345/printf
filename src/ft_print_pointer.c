#include "ft_printf.h"

void lu_to_hex(unsigned long num){
    char temp_buffer[16];
    int i = 0;
    char hex_table[16] = {'0', '1', '2', '3', '4',
                          '5', '6', '7', '8', '9',
                          'a', 'b','c','d','e','f'
    };

    while (num != 0){
        write(1, hex_table[num % 16], 1);
        temp_buffer[]
        num /= 16;
    }
}

void print_memory(va_list *arg_ptr, int *num_of_characters)
{
    void* res;
    res = va_arg(*arg_ptr, void*);
    printf("%p", res);
    lu_to_hex((unsigned long)res);
}