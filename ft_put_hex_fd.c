/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaatik <yalaatik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:51:15 by yalaatik          #+#    #+#             */
/*   Updated: 2025/01/27 13:15:03 by yalaatik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_hex_digits(unsigned int n)
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

int	ft_put_hex_fd(unsigned int n, int is_uppercase, int fd)
{
	const char	*base_lower;
	const char	*base_upper;

	base_lower = "0123456789abcdef";
	base_upper = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_put_hex_fd(n / 16, is_uppercase, fd);
		ft_put_hex_fd(n % 16, is_uppercase, fd);
	}
	else
	{
		if (is_uppercase == 1)
		{
			if (write(fd, &base_upper[n], 1) == -1)
				return (-1);
		}
		else
		{
			if (write(fd, &base_lower[n], 1) == -1)
				return (-1);
		}
	}
	return (count_hex_digits(n));
}
