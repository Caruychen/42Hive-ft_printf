/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:13:37 by cchen             #+#    #+#             */
/*   Updated: 2022/03/06 13:39:25 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	conv_char(t_vec *result, t_specs *specs)
{
	char	c;

	c = va_arg(specs->ap, int);
	return (vec_append_strn(result, &c, 1));
}

int	conv_string(t_vec *result, t_specs *specs)
{
	return (append_str(result, va_arg(specs->ap, char *)));
}

int	conv_num(t_vec *result, t_specs *specs)
{
	int		length;
	char	*s;
	char	spec;

	spec = specs->spec;
	specs->is_signed = (spec == 'i' || spec == 'd');
	s = g_modifier[specs->length](specs);
	if (!s)
		return (-1);
	length = append_str(result, s);
	ft_strdel(&s);
	return (length);
}

int	conv_ptr(t_vec *result, t_specs *specs)
{
	int		length;
	char	*x_str;
	char	*s;

	x_str = ft_ultoa(va_arg(specs->ap, uintptr_t), 16, FALSE);
	if (!x_str)
		return (-1);
	s = ft_strjoin("0x", x_str);
	if (!s)
	{
		ft_strdel(&x_str);
		return (-1);
	}
	length = append_str(result, s);
	ft_strdel(&x_str);
	ft_strdel(&s);
	return (length);
}

int	conv_flt(t_vec *result, t_specs *specs)
{
	double	value;
	char	*s;

	value = va_arg(specs->ap, double);
	if (value < 0)
	{
		vec_push(result, "-");
		value *= -1;
	}
	value += 0.5 / ft_pow(10, 6);
	s = ft_ultoa((unsigned long) value, 10, FALSE);
	append_str(result, s);
	ft_strdel(&s);
	vec_push(result, ".");
	value -= (unsigned long) value;
	value = value * ft_pow(10, 6);
	s = ft_ultoa((unsigned long) value, 10, FALSE);
	padding(result, 6 - ft_strlen(s));
	append_str(result, s);
	ft_strdel(&s);
	return (result->len);
}
