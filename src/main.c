#include "ft_printf.h"
#include "libft.h"
int main() {
    int mem = 12;
    printf("Original -> %p\n", &mem);
    int result = ft_printf("hi%d%s%p",42,"hello world",&mem);
    printf("\nNumber of characters read: %d", result);
    return 0;
}
