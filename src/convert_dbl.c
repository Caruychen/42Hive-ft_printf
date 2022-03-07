/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dbl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:13:37 by cchen             #+#    #+#             */
/*   Updated: 2022/03/07 21:27:15 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	conv_dbl(t_vec *result, t_specs *specs)
{
	double		value;
	unsigned int	precision;
	char		*s;

	if (specs->length == L)
		value = va_arg(specs->ap, long double);
	else
		value = va_arg(specs->ap, double);
	precision = 6 * !specs->precision_on + specs->precision;
	if (value < 0)
	{
		vec_push(result, "-");
		value *= -1;
	}
	value += 0.5 / ft_pow(10, precision);
	s = ft_ultoa((unsigned long) value, 10, FALSE);
	append_str(result, s);
	ft_strdel(&s);
	if (specs->precision_on && !specs->precision)
		return (result->len);
	vec_push(result, ".");
	value -= (unsigned long) value;
	value = value * ft_pow(10, precision);
	s = ft_ultoa((unsigned long) value, 10, FALSE);
	padding(result, precision - ft_strlen(s));
	append_str(result, s);
	ft_strdel(&s);
	return (result->len);
}
