/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:11:46 by cchen             #+#    #+#             */
/*   Updated: 2022/02/21 12:30:36 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
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
	if (**format == 'p')
		parse_ptr(result, va_arg(ap, uintptr_t));
	(*format)++;
	return (result->len);
}
*/
int	parse_conversion(t_vec *result, const char **format, t_specs specs)
{
	int		index;

	specs.spec = **format;
	index = 0;
	if (ft_islower(**format) * (**format - 'a'))
		index = **format - 'a';
	else if (ft_isupper(**format))
		index = **format - 'A';
	g_dispatcher[index](result, specs);
	(*format)++;
	return (result->len);
}

int	parse(t_vec *result, const char *format, t_specs specs)
{
	const char	*p;

	p = format;
	while (*p)
	{
		if (*p++ == '%')
		{
			if (vec_append_strn(result, format, (p - 1) - format) < 0)
				return (-1);
			parse_conversion(result, &p, specs);
			format = p;
		}
	}
	if (vec_append_strn(result, format, p - format) < 0)
		return (-1);
	return (0);
}
