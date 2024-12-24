#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    int total_len;
    va_list args;
    int check;

    va_start(args, format);
    total_len = 0;
    while(*format)
    {
        if (*format == '%' && *(format + 1) != '\0')
            {
                check = ft_format(*(format + 1), args);
                if (check == (-1))
                    return (total_len);
                else
                    total_len += check;
                format = format + 2;
            }
        else
        {
            total_len += ft_putchar_fd(*format, 1);
            format++;
        }
    }
    va_end(args);
    return (total_len);
}
