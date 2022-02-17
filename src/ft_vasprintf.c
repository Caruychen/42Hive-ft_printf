/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:39:23 by cchen             #+#    #+#             */
/*   Updated: 2022/02/17 10:53:33 by cchen            ###   ########.fr       */
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

int	vec_append_n(t_vec *dst, const void *src, size_t n)
{
	size_t	new_size;
	int		ret;

	if (!dst || !src)
		return (-1);
	if (!dst->memory)
		vec_new(dst, 1, dst->elem_size);
	new_size = (dst->len + n) * dst->elem_size;
	if (dst->alloc_size < new_size)
	{
		if (dst->alloc_size * 2 < new_size)
			ret = vec_resize(dst, new_size);
		else
			ret = vec_resize(dst, dst->alloc_size * 2);
		if (ret < 0)
			return (-1);
	}
	ft_memcpy(&dst->memory[dst->elem_size * dst->len], src, n * dst->elem_size);
	dst->len += n;
	return (1);
}

int	ft_vasprintf(char **ret, const char *format, va_list ap)
{
	t_vec	result;
	const char	*p;

	if (vec_new(&result, 1, sizeof(char)) == -1)
		return (-1);
	p = format;
	while (*p)
	{
		if (*p++ == '%')
		{
			vec_append_n(&result, format, p - format);
			format = p;
		}
	}
	return (result.len);
}
