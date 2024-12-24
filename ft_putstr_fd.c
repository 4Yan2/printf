#include "ft_printf.h"

int	ft_putstr_fd(char const*s, int fd)
{
	if (!s)
		return (ft_putstr_fd("(null)", fd));
	return ((int)write(fd, s, ft_strlen(s)));
}