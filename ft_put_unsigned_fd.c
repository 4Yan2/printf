#include "ft_printf.h"

int	ft_testlen_unsigned(unsigned int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_put_unsigned_fd(unsigned int n, int fd)
{
	int	len;

	len = ft_testlen_unsigned(n);
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else
	{
		ft_put_unsigned_fd(n / 10, fd);
		ft_put_unsigned_fd(n % 10, fd);
	}
	return (len);
}