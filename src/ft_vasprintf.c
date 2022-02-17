/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:39:23 by cchen             #+#    #+#             */
/*   Updated: 2022/02/17 13:42:25 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "libft.h"

int	vec_append_str(t_vec *dst, const void *src)
{
	size_t	n;

	n = ft_strlen(src);
	return (vec_append_strn(dst, src, n));
}

int	parse_char(t_vec *result, int c)
{
	vec_append_strn(result, &c, 1);
	return (1);
}

int	parse_string(t_vec *result, const char *s)
{
	if (s == NULL)
		return (vec_append_str(result, "(null)"));
	return (vec_append_str(result, s));
}

int	parse_signed_int(t_vec *result, int n)
{
	int		length;
	char	*s;

	s = ft_itoa(n);
	length = parse_string(result, s);
	free(s);
	return (length);
}

int	parse_conversion(t_vec *result, const char **format, va_list ap)
{
	if (**format == 'c')
		parse_char(result, va_arg(ap, int));
	if (**format == 'd' || **format == 'i')
		parse_signed_int(result, va_arg(ap, int));
	if (**format == 's')
		parse_string(result, va_arg(ap, char *));
	(*format)++;
	return (result->len);
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
			if (vec_append_strn(&result, format, (p - 1) - format) < 0)
				return (-1);
			parse_conversion(&result, &p, ap);
			format = p;
		}
	}
	vec_append_strn(&result, format, p - format);
	*ret = result.memory;
	return (result.len);
}
