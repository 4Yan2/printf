/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaatik <yalaatik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:00:14 by yalaatik          #+#    #+#             */
/*   Updated: 2025/01/27 14:57:43 by yalaatik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_hex_digits_ull(unsigned long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int	ft_put_hex_ull_fd(unsigned long long n, int is_uppercase, int fd)
{
	const char	*base_lower;
	const char	*base_upper;
	int			printed_chars;

	base_lower = "0123456789abcdef";
	base_upper = "0123456789ABCDEF";
	printed_chars = count_hex_digits_ull(n);
	if (n >= 16)
	{
		ft_put_hex_ull_fd(n / 16, is_uppercase, fd);
		ft_put_hex_ull_fd(n % 16, is_uppercase, fd);
	}
	else
	{
		if (write(fd, &base_lower[n], 1) == -1)
			return (-1);
	}
	return (printed_chars);
}

int	ft_put_ptr(void *ptr)
{
	unsigned long long	addr;

	if (!ptr)
		return (ft_putstr_fd("(nil)", 1));
	addr = (unsigned long long)ptr;
	if (write(1, "0x", 2) == -1)
		return (-1);
	return (2 + ft_put_hex_ull_fd(addr, 0, 1));
}
