#include "ft_printf.h"

int	ft_putstr_fd(char const*s, int fd)
{
	size_t	i;

	if (!s)
		return (ft_putstr_fd("(null)", fd));
    //	return (0);
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
}