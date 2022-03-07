/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dbl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:13:37 by cchen             #+#    #+#             */
/*   Updated: 2022/03/07 23:13:10 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	append_num(t_vec *result, double value)
{
	char	*s;
	int		len;

	s = ft_ultoa((unsigned long) value, 10, FALSE);
	if (!s)
		return (-1);
	len = ft_strlen(s);
	if (vec_append_strn(result, s, len) == -1)
		len = -1;
	ft_strdel(&s);
	return (len);
}

static int	append_decimals(t_vec *result, double value, unsigned int precision)
{
	int	len;

	if (vec_push(result, ".") == -1)
		return (-1);
	value = (value - (unsigned long) value) * ft_pow(10, precision);
	len = append_num(result, value);
	if (len == -1)
		return (-1);
	padding(result, precision - len);
	return (result->len);
}

int	conv_dbl(t_vec *result, t_specs *specs)
{
	double			value;
	unsigned int	precision;

	if (specs->length == L)
		value = va_arg(specs->ap, long double);
	else
		value = va_arg(specs->ap, double);
	if (value < 0)
	{
		vec_push(result, "-");
		value *= -1;
	}
	precision = 6 * !specs->precision_on + specs->precision;
	value += 0.5 / ft_pow(10, precision);
	append_num(result, value);
	if (specs->precision_on && !specs->precision)
		return (result->len);
	return (append_decimals(result, value, precision));
}
