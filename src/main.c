#include "ft_printf.h"
#include "libft.h"
int main() {
    int mem = 12;
	char te = 'a';
	printf("Original -> %u\n", 4294967294);
    printf("Original -> %p\n", &mem);
    int result = ft_printf("hi%d%s%p%c%u%X",42,"hello world",&mem, te,
			4294967294, 50031310
			);
    printf("\nNumber of characters read: %d", result);
    return 0;
}
