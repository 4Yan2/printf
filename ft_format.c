/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaatik <yalaatik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:40:29 by yalaatik          #+#    #+#             */
/*   Updated: 2025/01/27 10:40:43 by yalaatik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd((char)va_arg(args, int), 1));
	if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	if (c == 'p')
		return (ft_put_ptr(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	if (c == 'u')
		return (ft_put_unsigned_fd(va_arg(args, unsigned int), 1));
	if (c == 'x')
		return (ft_put_hex_fd(va_arg(args, unsigned int), 0, 1));
	if (c == 'X')
		return (ft_put_hex_fd(va_arg(args, unsigned int), 1, 1));
	if (c == '%')
		return (ft_putchar_fd('%', 1));
	else
		return (-1);
}
