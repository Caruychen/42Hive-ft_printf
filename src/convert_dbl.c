/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:13:37 by cchen             #+#    #+#             */
/*   Updated: 2022/03/07 11:21:40 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

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
