/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:39:23 by cchen             #+#    #+#             */
/*   Updated: 2022/02/16 15:05:56 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "libft.h"

int	parse_char(int fd, int c)
{
	ft_putchar_fd((char) c, fd);
	return (1);
}

int	parse_string(int fd, const char *s)
{
	int	length;

	length = 0;
	if (s == NULL)
	{
		ft_putstr_fd("(null)", fd);
		return (0);
	}
	while (s[length])
		++length;
	write(fd, s, length);
	return (length);
}

int	parse_signed_int(int fd, int n)
{
	int		length;
	char	*s;

	s = ft_itoa(n);
	length = parse_string(fd, s);
	free(s);
	return (length);
}

int	parse_conversion(int fd, const char **format, va_list ap)
{
	int	length;

	length = 0;
	if (**format == 'c')
		length = parse_char(fd, va_arg(ap, int));
	if (**format == 'd' || **format == 'i')
		length = parse_signed_int(fd, va_arg(ap, int));
	if (**format == 's')
		length = parse_string(fd, va_arg(ap, char *));
	(*format)++;
	return (length);
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int	index;
	int	result;

	result = 0;
	index = 0;
	while (format[index])
	{
		if (format[index] == '%')
		{
			write(fd, format, index);
			format += index + 1;
			result += index;
			result += parse_conversion(fd, &format, ap);
			index = 0;
		}
		++index;
	}
	write(fd, format, index);
	result += index;
	return (result);
}
