/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaatik <yalaatik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:03:46 by yalaatik          #+#    #+#             */
/*   Updated: 2025/01/27 13:31:20 by yalaatik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_form_set(const char *format, va_list args);
int		ft_printf(const char *format, ...);
int		ft_format(char c, va_list args);
int		ft_put_unsigned_fd(unsigned int n, int fd);
int		ft_testlen_unsigned(unsigned int n);
int		ft_putnbr_fd(int n, int fd);
int		ft_testlen(int n);
int		ft_putstr_fd(char const*s, int fd);
int		ft_put_ptr(void *ptr);
int		count_hex_digits(unsigned int n);
int		ft_put_hex_fd(unsigned int n, int is_uppercase, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_put_hex_ull_fd(unsigned long long n, int is_uppercase, int fd);
int		count_hex_digits_ull(unsigned long long n);
size_t	ft_strlen(const char *str);

#endif
