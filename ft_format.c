/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaatik <yalaatik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:40:29 by yalaatik          #+#    #+#             */
/*   Updated: 2025/02/01 16:01:34 by yalaatik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list args, int fd)
{
	if (c == 'c')
		return (ft_putchar_fd((char)va_arg(args, int), fd));
	if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), fd));
	if (c == 'p')
		return (ft_put_ptr_fd(va_arg(args, void *), fd));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), fd));
	if (c == 'u')
		return (ft_put_unsigned_fd(va_arg(args, unsigned int), fd));
	if (c == 'x')
		return (ft_put_hex_fd(va_arg(args, unsigned int), 0, fd));
	if (c == 'X')
		return (ft_put_hex_fd(va_arg(args, unsigned int), 1, fd));
	if (c == '%')
		return (ft_putchar_fd('%', fd));
	else
		return (-1);
}
