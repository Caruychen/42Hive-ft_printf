/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:13:57 by cchen             #+#    #+#             */
/*   Updated: 2022/03/07 22:09:01 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	conv_char(t_vec *result, t_specs *specs)
{
	char	c;

	c = va_arg(specs->ap, int);
	return (vec_append_strn(result, &c, 1));
}

int	conv_string(t_vec *result, t_specs *specs)
{
	char	*str;
	size_t	length;

	str = va_arg(specs->ap, char *);
	if (!str)
		str = "(null)";
	length = ft_strlen(str);
	if (specs->precision_on && length > specs->precision)
		length = specs->precision;
	return (vec_append_strn(result, str, length));
}
