#include "ft_printf.h"

int count_hex_digits(unsigned int n)
{
    int count = 0;

    if (n == 0)
        return (1);
    while (n > 0)
    {
        n /= 16;
        count++;
    }
    return (count);
}

int	ft_put_hex_fd(unsigned int n, int is_uppercase, int fd)
{
	const char	*base_lower;
	const char	*base_upper;
	int			printed_chars;

	base_lower = "0123456789abcdef";
	base_upper = "0123456789ABCDEF";
	printed_chars = count_hex_digits(n);
	if (n >= 16)
	{
		ft_put_hex_fd(n / 16, is_uppercase, fd);
		ft_put_hex_fd(n % 16, is_uppercase, fd);
	}
	else
	{
		if (is_uppercase == 1)
			write(fd, &base_upper[n], 1);
		else
			write(fd, &base_lower[n], 1);
	}
	return (printed_chars);
}