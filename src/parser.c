/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:11:46 by cchen             #+#    #+#             */
/*   Updated: 2022/02/18 11:30:26 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

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

int	parse_uint(t_vec *result, int n, int base, int uppercase)
{
	int		length;
	char	*s;

	s = ft_uitoa(n, base, uppercase);
	length = parse_string(result, s);
	free(s);
	return (length);
}

int	parse_octal(t_vec *result, int n)
{
	int		length;
	char	*s;

	s = ft_uitoa(n, 8, 0);
	length = parse_string(result, s);
	free(s);
	return (length);
}

int	parse_hex(t_vec *result, int n, int uppercase)
{
	int		length;
	char	*s;

	s = ft_uitoa(n, 16, uppercase);
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
	if (**format == 'o')
		parse_uint(result, va_arg(ap, int), 8, FALSE);
	if (**format == 'u')
		parse_uint(result, va_arg(ap, int), 10, FALSE);
	if (**format == 'x')
		parse_uint(result, va_arg(ap, int), 16, FALSE);
	if (**format == 'X')
		parse_uint(result, va_arg(ap, int), 16, TRUE);
	(*format)++;
	return (result->len);
}

int	parse(t_vec *result, const char *format, va_list ap)
{
	const char	*p;

	p = format;
	while (*p)
	{
		if (*p++ == '%')
		{
			if (vec_append_strn(result, format, (p - 1) - format) < 0)
				return (-1);
			parse_conversion(result, &p, ap);
			format = p;
		}
	}
	if (vec_append_strn(result, format, p - format) < 0)
		return (-1);
	return (0);
}
