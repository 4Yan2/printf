/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaatik <yalaatik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:49:20 by yalaatik          #+#    #+#             */
/*   Updated: 2025/02/01 15:13:23 by yalaatik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_form_set(const char *format, va_list args)
{
	int check;
	int total_len;

	total_len = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			check = ft_format(*(format + 1), args);
			if (check == (-1))
				return (-1);
			total_len += check;
			format += 2;
			continue;
		}
		if (*format == '\0')
			break;
		if (*format == '%' && *(format + 1) == '\0')
			return (-1);
		else
		{
			if (ft_putchar_fd(*format, 1) == -1)
				return (-1);
			total_len++;
			format++;
		}
	}
	return (total_len);
}

int ft_printf(const char *format, ...)
{
	int total_len;
	va_list args;

	va_start(args, format);
	total_len = ft_form_set(format, args);
	va_end(args);
	return (total_len);
}
#include <stdio.h>

int main(void)
{
	int len = ft_printf("yo la team %i %% %s%c%w/%s%s%%%u",42, "tgtgtg", 'c', "oaoaoa", "babababa", 7878);
	ft_printf("\nlen => %i", len);
//	len = printf("yo la team %i %% %s%c %s%s%%%u",42, "tgtgtg",'c', "oaoaoa", "babababa", 7878);
//	printf("\nlen => %i", len);
	return (0);
}