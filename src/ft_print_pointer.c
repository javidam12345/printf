#include "ft_printf.h"

#define HEX_TABLE "0123456789abcdef"
#define CAP_HEX_TABLE "0123456789ABCDEF"


void lu_to_hex(unsigned long num, int *num_of_characters, int is_upper){
    char temp_buffer[16];
    int i;
    char * hex_table;

    hex_table = HEX_TABLE;
    i = 0;
	if (is_upper)
        hex_table = CAP_HEX_TABLE;
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
    if (!res){
        write(1,"(null)",6);
        (*num_of_characters) += 6;
        return ;
    }
	write(1, "0x", 2);	
	(*num_of_characters) += 2;
	lu_to_hex((unsigned long long)res, num_of_characters, 0);
}
