#include "ft_printf.h"

void lu_to_hex(unsigned long num, int *num_of_characters, int is_upper){
    char temp_buffer[16];
    int i = 0;
    char hex_table[] = "0123456789abcdef";
	if (is_upper)
		while (hex_table[i++])
			hex_table[i] = ft_toupper(hex_table[i]);
	i = 0;
    while (num != 0)
	{
        temp_buffer[i++] = hex_table[num % 16];
        num /= 16;
    }
	(*num_of_characters) += i;
	while (--i >= 0)
	{
		write(1, &temp_buffer[i], 1);
	}
}

void print_memory(va_list *arg_ptr, int *num_of_characters)
{
    void* res;
    res = va_arg(*arg_ptr, void*);	
	write(1, "0x", 2);	
	(*num_of_characters) += 2;
	lu_to_hex((unsigned long)res, num_of_characters, 0);
}
