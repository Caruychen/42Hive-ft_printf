/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:13:37 by cchen             #+#    #+#             */
/*   Updated: 2022/03/03 08:13:10 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

int	parse_char(t_vec *result, t_specs *specs)
{
	char	c;

	c = va_arg(specs->ap, int);
	return (vec_append_strn(result, &c, 1));
}

int	parse_string(t_vec *result, t_specs *specs)
{
	return (append_str(result, va_arg(specs->ap, char *)));
}

int	parse_num(t_vec *result, t_specs *specs)
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
	free(s);
	return (length);
}

int	parse_ptr(t_vec *result, t_specs *specs)
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
		free(x_str);
		return (-1);
	}
	length = append_str(result, s);
	free(x_str);
	free(s);
	return (length);
}

int	parse_flt(t_vec *result, t_specs *specs)
{
	double	value;

	value = va_arg(specs->ap, double);
	printf("%f\n", ft_fmod(9.7, 2.3));
	printf("%f\n", ft_fmod(42, 5));
	printf("%f\n", ft_fmod(42, 10));

	return (result->len);
}
