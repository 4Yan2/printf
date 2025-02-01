/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaatik <yalaatik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:05:30 by yalaatik          #+#    #+#             */
/*   Updated: 2025/01/27 11:54:56 by yalaatik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (ft_putchar_fd(n + '0', fd) == -1)
			return (-1);
	}
	else
	{
		ft_put_unsigned_fd(n / 10, fd);
		ft_put_unsigned_fd(n % 10, fd);
	}
	return (len);
}
