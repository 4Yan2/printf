#include "ft_printf.h"

int count_hex_digits_ull(unsigned long long n)
{
    int count = 0;

    if (n == 0)
        return 1;
    while (n > 0)
    {
        n /= 16;
        count++;
    }
    return count;
}

int ft_put_hex_ull_fd(unsigned long long n, int is_uppercase, int fd)
{
    const char  *base_lower = "0123456789abcdef";
    const char  *base_upper = "0123456789ABCDEF";
    int         printed_chars;

    printed_chars = count_hex_digits_ull(n);
    if (n >= 16)
    {
        ft_put_hex_ull_fd(n / 16, is_uppercase, fd);
        ft_put_hex_ull_fd(n % 16, is_uppercase, fd);
    }
    else
    {
        if (is_uppercase)
            write(fd, &base_upper[n], 1);
        else
            write(fd, &base_lower[n], 1);
    }
    return (printed_chars);
}

int	ft_put_ptr(void *ptr)
{
	unsigned long long addr;

	if (!ptr)
		return (ft_putstr_fd("0x0", 1));
	addr = (unsigned long long)ptr;
	write(1, "0x", 2);
	return (2 + ft_put_hex_ull_fd(addr, 0, 1));
}