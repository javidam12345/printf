#include "ft_printf.h"
#include <stdio.h>

int ft_printf(const char *format, ...)
{
    va_list argp;
    va_start(argp, format);
    analize_string(format, argp);
    va_end(argp);
    return 0;
}

void analize_string(const char* format, va_list argp)
{
    while (*format != '\0')
    {
        if (*format == '%')
        {
            printf("detected element to replace");
            int test = va_arg(argp, int);
            printf("Num %d",test);
        }
        else
        {
            printf("Lets write normal character");
        }
        format++;
    }
}
