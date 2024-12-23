#include "libftprintf.a"
#include <stdarg.h>

int ft_printf(const char *format, ...)
{
    int tailletotale;
    va_list args;

    va_start(args, format);
    tailletotale = 0;
    while(*format)
    {
        if (*format == '%' && *(format + 1) != '\0')
            {
                tailletotale += ft_format(*(format + 1), args);
                format = format + 2;
            }
        else
        {
            tailletotale += ft_putchar(*format);
            format++;
        }
    }
    va_end(args);
    return (tailletotale);
}